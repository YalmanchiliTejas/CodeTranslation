#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vvi vector<vector<int>>
#define vec vector
#define pq priority_queue
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (int (i) = (0); (i) < (n); ++(i))
#define repp(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) cerr<<"("<<#x<<", "<<#y<<") = "<<"("<<x<<", "<<y<<")"<<endl;
#define debug3(x, y, z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = "<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
#define debugB(x, y) cerr<<#x<<": "<<bitset<y>(x) << endl;
#define line() cerr << "---------------" << endl;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

template<typename T>
void printA(vector<T> &printArray, char between = ' ') {
   int paSize = printArray.size();
   for (int i = 0; i < paSize; i++) { cerr << printArray[i] << between;}
   if (between != '\n') {cerr << endl;}
}

// ------------------------------------------------------------------------------------------

int h, w;
char a[10][10];

void dfs(int y, int x) {
   a[y][x] = '*';
   int tx = x + 1;
   if (y >= 0 && y < h && tx >= 0 && tx < w && a[y][tx] == '#') {
      while (1) {
         if (y < 0 && y >= h && tx < 0 && tx >= w && a[y][tx] != '#') break;
         a[y][tx] = '*';
         tx++;
      }
      dfs(y, tx-1);
      return;
   }
   int ty = y + 1;
   if (ty >= 0 && ty < h && x >= 0 && x < w && a[ty][x] == '#') {
      while (1) {
         if (ty < 0 && ty >= h && x < 0 && x >= w && a[ty][x] != '#') break;
         a[ty][x] = '*';
         ty++;
      }
      dfs(ty-1, x);
      return;
   }
}

int main() {
   cin >> h >> w;
   rep (i, h) {
      rep (j, w) {
         cin >> a[i][j];
      }
   }

   // dfs(0, 0);
   int y = 0, x = 0;
   int oy = 0, ox = 0;
   a[y][x] = '*';
   int cnt = 0;
   while (1) {
      if (y+1>=0 && y+1<h && x>=0 && x<w && a[y+1][x]=='#') {
         while (1) {
            y++;
            if (y < 0 || y >= h || x < 0 || x >= w || a[y][x] != '#') break;
            a[y][x] = '*';
         }
         y--;
      }

      if (y>=0 && y<h && x+1>=0 && x+1<w && a[y][x+1]=='#') {
         while (1) {
            x++;
            if (y < 0 || y >= h || x < 0 || x >= w || a[y][x] != '#') break;
            a[y][x] = '*';
         }
         x--;
      }

      if (oy == y || ox == x) {
         cnt++;
      } else {
         cnt = 0;
      }
      oy = y, ox = x;

      if (cnt >= 10) break;

      if (y == h-1 && x == w-1) {
         break;
      }
   }

   rep (i, h) {
      rep (j, w) {
         if (a[i][j] == '#') {
            puts("Impossible");
            return 0;
         }
      }
   }
   puts("Possible");

   return 0;
}