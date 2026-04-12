#include "bits/stdc++.h"
 
using ll = long long;
using namespace std;


void solveCase() {
   int n, m;
   cin >> n >> m;
   vector <string> v(n);

   for(auto &e: v) {
      cin >> e;
   }

   bool ok = true;
   int hashcnt = 0;
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         if(v[i][j] == '#') {
            hashcnt += 1;
            int cnt = 0;
            cnt += (i > 0) && v[i - 1][j] == '#';
            cnt += (j > 0) && v[i][j - 1] == '#';
            if(cnt == 0) {
               ok &= ((i == 0) && (j == 0)) || ((i + 1 == n) && (j + 1 == m));
            } else {
               ok &= (cnt == 1);
            }
         }
      }
   }
   ok &= (hashcnt + 1 == n + m);
   cout << (ok ? "Possible" : "Impossible") << endl;
}

 
int main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   
   int testcase = 1;
   // cin >> testcase;
 
   for(int i = 0; i < testcase; i++) {
      solveCase();
   }
 
   return 0;
}