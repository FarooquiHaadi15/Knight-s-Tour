An input file will contain the demensions of a chess board on one line as well as where the knight is starting on the chessboard in the line below. 
Afterwards, the number of 'holes' on the chess board are indicated followed by the coordinates the holes are located at. The knight will be tasked to traverse the chess board, visiting each space once. 
Once this is done, the array will be printed out indicating the order the knight visited the square. 

Example:

Input : 
3 3
0 0
1
1 1

Output:
A closed tour exists!
+--+--+--+
| 1| 6| 3|
+--+--+--+
| 4|XX| 8|
+--+--+--+
| 7| 2| 5|
+--+--+--+
Each number represents the order where the knight visited on the board with '1' being the start point. "XX" represents a hole.
