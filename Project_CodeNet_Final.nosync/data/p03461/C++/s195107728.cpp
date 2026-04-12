#include <bits/stdc++.h>

using namespace std;

int d[15][15];
int f[105][105];

int main() {
   ios_base::sync_with_stdio(false);
   int na, nb;
   cin >> na >> nb;
   for (int i = 1; i <= na; ++i) {
      for (int j = 1; j <= nb; ++j) {
         cin >> d[i][j];
      }
   }
   for (int nx = 0; nx < 105; ++nx) {
      for (int ny = 0; ny < 105; ++ny) {
         for (int i = 1; i <= na; ++i) {
            for (int j = 1; j <= nb; ++j) {
               f[nx][ny] = max(f[nx][ny], d[i][j] - i * nx - j * ny);
            }
         }
      }
   }
   for (int i = 1; i <= na; ++i) {
      for (int j = 1; j <= nb; ++j) {
         bool found = false;
         for (int nx = 0; nx < 105; ++nx) {
            for (int ny = 0; ny < 105; ++ny) {
               if (f[nx][ny] + i * nx + j * ny == d[i][j]) {
                  found = true;
               }
            }
         }
         if (!found) {
            cout << "Impossible\n";
            return 0;
         }
      }
   }
   cout << "Possible\n";
   cout << 210 << " " << 11233 << "\n";
   for (int i = 0; i < 104; ++i) {
      cout << i + 1 << " " << i + 2 << " X\n";
      cout << i + 107 << " " << i + 106 << " Y\n";
   }
   for (int nx = 0; nx < 105; ++nx) {
      for (int ny = 0; ny < 105; ++ny) {
         cout << nx + 1 << " " << ny + 106 << " " << f[nx][ny] << "\n";
      }
   } 
   cout << 1 << " " << 106 << "\n";
}