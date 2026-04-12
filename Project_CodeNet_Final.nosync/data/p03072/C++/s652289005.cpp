#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;
#define rep(i,b) for(ll i=0;i<(b);++i)
#define rep1(i,b) for(ll i=1;i<=(b);++i)
#define vec vector
#define FOR(I,A,B) for(ll I=(A);I<(B);++I)
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;

ll N;
ll H[25];

int main() {
   cin >> N;
   rep(i, N) {
      cin >> H[i];
   }
   int cnt = 1;
   for (int j=1;j<N;j++) {
      int isok = 1;
      rep(k, j) {
         if (H[k] > H[j]) { 
            isok = 0;
         }
      }
      if (isok) {
         cnt++;
      }
   }
   cout << cnt << endl;
}
