# 2 "2302.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>


namespace solution {
   using namespace std;

   typedef istringstream ISS;
   typedef ostringstream OSS;
   typedef vector<string> VS;
   typedef long long LL;
   typedef int INT;
   typedef vector<INT> VI;
   typedef vector<VI> VVI;
   typedef pair<INT, INT> II;
   typedef vector<II> VII;

   ostream& operator << ( ostream& os, II& p ) {
      os << "(" << p.first << "," << p.second << ")";
      return os;
   }

   const int SIZE = 51;
   const int MAX_M = 1011;
   const int NONE = -1;
   const char WALL = '#';
   int H, W, M;
   string S[SIZE];
   int X[SIZE][SIZE];
   int Y[SIZE][SIZE];
   int Z[SIZE][SIZE];
   II D[MAX_M];
   int T[SIZE][SIZE][MAX_M];
   int TC[SIZE][SIZE];
   int A;

   class Node {
   public:
      int r;
      int c;
      Node(){}
      Node(int r, int c): r(r), c(c) {}
   };
   typedef queue<Node> Queue;
   const int dr[4] = { 0, 0, 1, -1 };
   const int dc[4] = { 1, -1, 0, 0 };

   void bfs( int sr, int sc, int gr, int gc ) {
      Queue Q;
      Q.push( Node( sr, sc ) );

      II P[H][W];
      for ( int i = 0; i < H; ++ i ) {
         for ( int j = 0; j < W; ++ j ) {
            P[i][j] = II( NONE, NONE );
         }
      }

      while ( ! ( Q.empty() ) ) {
         Node node = Q.front();
         Q.pop();

         int r = node.r;
         int c = node.c;

         if ( r == gr && c == gc ) {
            VII route;
            while ( r != sr || c != sc ) {
               route.push_back( II( r, c ) );
               int pr = P[r][c].first;
               int pc = P[r][c].second;
               r = pr;
               c = pc;
            }
            reverse( route.begin(), route.end() );
            for ( VII::iterator it_i = route.begin(); it_i != route.end(); ++ it_i ) {
               int r = (*it_i).first;
               int c = (*it_i).second;
               T[r][c][TC[r][c]++] = A ++;
            }
            return;
         }

         for ( int i = 0; i < 4; ++ i ) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if ( nr < 0 || nr >= H || nc < 0 || nc >= W ) continue;
            if ( P[nr][nc].first != NONE ) continue;
            if ( S[nr][nc] == WALL ) continue;
            P[nr][nc] = II( r, c );
            Q.push( Node( nr, nc ) );
         }
      }
   }

   class Solution {
   private:
      void init() {
         for ( int i = 0; i < H; ++ i ) {
            for ( int j = 0; j < W; ++ j ) {
               TC[i][j] = 0;
            }
         }
         A = 0;
      }

      bool input() {
         if ( ! ( cin >> H >> W >> M ) ) return false;
         for ( int i = 0; i < H; ++ i ) {
            cin >> S[i];
         }
         for ( int i = 0; i < H; ++ i ) {
            for ( int j = 0; j < W; ++ j ) {
               cin >> X[i][j];
            }
         }
         for ( int i = 0; i < H; ++ i ) {
            for ( int j = 0; j < W; ++ j ) {
               cin >> Y[i][j];
            }
         }
         for ( int i = 0; i < H; ++ i ) {
            for ( int j = 0; j < W; ++ j ) {
               cin >> Z[i][j];
            }
         }
         for ( int i = 0; i < M; ++ i ) {
            cin >> D[i].first >> D[i].second;
         }
         return true;
      }

      int solve() {
         int sr = D[0].first;
         int sc = D[0].second;
         T[sr][sc][TC[sr][sc]++] = A ++;
         for ( int i = 0; i + 1 < M; ++ i ) {
            bfs( D[i].first, D[i].second, D[i+1].first, D[i+1].second );
         }

         int res = 0;
         for ( int i = 0; i < H; ++ i ) {
            for ( int j = 0; j < W; ++ j ) {
               int n = TC[i][j];
               if ( n == 0 ) continue;
               res += Y[i][j] + Z[i][j];
               for ( int k = 0; k + 1 < n; ++ k ) {
                  int d = T[i][j][k+1] - T[i][j][k];
                  res += min( X[i][j] * d, Y[i][j] + Z[i][j] );
               }
            }
         }
         return res;
      }

   public:
      int run() {
         while ( init(), input() ) {
            cout << solve() << endl;
         }
         return 0;
      }
   };
}

int main() {
   using namespace solution;
   Solution s;
   return s.run();
}