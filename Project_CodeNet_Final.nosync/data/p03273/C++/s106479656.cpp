#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) x.begin(),x.end()
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;

using namespace std;

string bord[110];
int x[110],y[110];

int main() {
   int h,w;
   cin >> h >> w;
   rep(i,h)
   cin >> bord[i];
   
   rep(i,h){
      rep(j,w){
         if(bord[i][j]=='#'){
         x[i]=1; y[j]=1;
         }
      }
   }

   rep(i,h){
      if(x[i]){
         rep(j,w){
            if(y[j])
            cout << bord[i][j];
         }
         cout << endl;
      }
   }
}