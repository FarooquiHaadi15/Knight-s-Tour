#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include "ArgumentManager.h"
using namespace std;

const int MAXN = 10;

int board[MAXN][MAXN];
int RowMoves[] =    {-1,-2,-2,-1,1,2,2,1};
int ColumnMoves[] = {2,1,-1,-2,-2,-1,1,2};
int n, m;

int start_x, start_y; // Store the starting position

bool isValid(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m && board[x][y] == -1);
}

bool findClosedTour(int x, int y, int move_count, int numHoles) {
  
  
    if (move_count == ((n * m) - numHoles)) {
        // Check if the knight can return to the starting position
        for (int i = 0; i < 8; i++) {
            int next_x = x + RowMoves[i];
            int next_y = y + ColumnMoves[i];
            if (next_x == start_x && next_y == start_y) {
                // Closed tour found
                
                  return true;
              }
        }
        return false; // Knight cannot return to the starting position
    }

    for (int i = 0; i < 8; i++) {
        int next_x = x + RowMoves[i];
        int next_y = y + ColumnMoves[i];
        if (isValid(next_x, next_y)) {
            board[next_x][next_y] = move_count + 1;
            if (findClosedTour(next_x, next_y, move_count + 1, numHoles)) {
                return true;
            }else{
        
            board[next_x][next_y] = -1;  // Backtrack
            }
        }
    }

    return false;
}

  int main(int argc, char* argv[]) {

      ArgumentManager am(argc, argv);
      ifstream fin(am.get("input"));
      ofstream fout(am.get("output"));

    fin >> n >> m;
    int num_holes;
    fin>> start_x >> start_y >> num_holes;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = -1;
        }
    }

    board[start_x][start_y] = 1;

    for (int i = 0; i < num_holes; i++) {
        int hole_x, hole_y;
        fin >> hole_x >> hole_y;
        board[hole_x][hole_y] = -2;
    }

    if (!findClosedTour(start_x, start_y, 1, num_holes)){
        fout << "A closed tour does not exist!" << endl;
    }else{
      fout << "A closed tour exists!" << endl;
      for (int i = 0; i < n; i++) {
              for (int j = 0; j < m; j++) {
                  fout << "+--";
              }
              fout << "+" << endl;
              for (int j = 0; j < m; j++) {
                  if (board[i][j] == -2) {
                      fout << "|XX";
                  } else {
                      fout << "|" << setw(2) << board[i][j];
                  }
              }
              fout << "|" << endl;
          }
          for (int j = 0; j < m; j++) {
              fout << "+--";
          }
          fout << "+" << endl;
    }

    return 0;
}