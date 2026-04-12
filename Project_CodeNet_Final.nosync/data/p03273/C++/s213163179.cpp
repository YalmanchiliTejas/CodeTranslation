#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0 ; i<(n) ; i++)
#define repr(i,n) for(int i=(n) ; i>=0 ; i--)
#define FOR(i,m,n) for(int i=(m) ; i<(n) ; i++)
#define FORR(i,m,n) for(int i=(m) ; i>=(n) ; i--)

typedef long long ll;
typedef unsigned long long ull;

const int INF = 1000000000;

int main(){
   int H,W;cin >> H >> W;
   string a[H];
   rep(i,H)cin >> a[i];
   vector<bool> row(H,false),col(W,false);
   rep(i,H){
      rep(j,W){
         if(a[i][j] == '#'){
            row[i] = true;
            col[j] = true;
         }
      }
   }
   rep(i,H){
      if(row[i]){
         rep(j,W){
            if(col[j]){
               cout << a[i][j];
            }
         }
         cout << endl;
      }
   }
   return 0;
}