#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int grid[9][9] = {
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

bool present_in_row(int r, int n) {
   for(int c = 0; c < 9; c++) {
      if (grid[r][c] == n) return true;
   }
   return false;
}

bool present_in_col(int c, int n) {
   for(int r = 0; r < 9; r++) {
      if (grid[r][c] == n) return true;
   }
   return false;
}

bool present_in_block(int block_r, int block_c, int n) {
   for(int r = 0; r < 3; r++) {
      for(int c = 0; c < 3; c++) {
         if (grid[r + block_r][c + block_c] == n) return true;
      }
   }
   return false;
}

bool empty_place(int &r, int &c) {
   for(r = 0; r < 9; r++) {
      for(c = 0; c < 9; c++) {
         if (grid[r][c] == 0) return true;
      }
   }
   return false;
}

bool valid_place(int r, int c, int n) {
   int block_r = r - r%3;
   int block_c = c - c%3;
   return !present_in_row(r, n) && !present_in_col(c, n) && !present_in_block(block_r, block_c, n);
}

void grid_format() {
   for(int r = 0; r < 9; r++) {
      for(int c = 0; c < 9; c++) {
         if(c == 3 || c == 6) {
            cout << " | ";
         }
         cout << grid[r][c] << " ";
      }
      if(r == 2 || r == 5) {
         cout << endl;
         for(int i = 0; i < 9; i++) {
            cout << "---";
         }
      }
      cout << endl;
   }
}

bool solver() {
   int row;
   int col;
   if (!empty_place(row, col)) {
      return true;
   }
   for (int n = 1; n <= 9; n++) {
      if(valid_place(row, col, n)) {
         grid[row][col] = n;
         if (solver()) {
            return true;
         }
         grid[row][col] = 0;
      }
   }
   return false;
}

int main() {
   cout << "Please enter a 9x9 matrix:" << endl;
   for(int r = 0; r < 9; r++) {
      int x;
      string s;
      getline(cin, s);
      istringstream ss(s);
      for(int c = 0; c < 9; c++) {
         ss >> x;
         grid[r][c] = x;
      }
   }
   if (solver() == true) {
      grid_format();
   } else {
      cout << "The grid was not solved.";
   }
}