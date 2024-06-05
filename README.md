An input file will contain the demensions of a chess board on one line as well as where the knight is starting on the chessboard in the line below. 
Afterwards, the number of 'holes' on the chess board are indicated followed by the coordinates the holes are located at. The knight will be tasked to traverse the chess board, visiting each space once. 
Once this is done, the array will be printed out indicating the order the knight visited the square. 

Example:

Input : 
8 8
0 0
0

Output:
0  59  38  33  30  17   8  63
37  34  31  60   9  62  29  16
58   1  36  39  32  27  18   7
35  48  41  26  61  10  15  28
42  57   2  49  40  23   6  19
47  50  45  54  25  20  11  14
56  43  52   3  22  13  24   5
51  46  55  44  53   4  21  12

Each number represents the order where the knight visited on the board with '0' being the start point
