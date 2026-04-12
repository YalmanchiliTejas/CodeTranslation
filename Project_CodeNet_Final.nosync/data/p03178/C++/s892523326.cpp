#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD (int)(1e9+7)
#define EPS 1e-8
#define INF 1e9+10
#define INFL 1e18
typedef long long ll;
using namespace std;
ll dp[10010][101][2];
int main()
{
   string K;
   int D;
   cin >> K >> D;
   int L = K.size();
   dp[0][0][0]=1;
   rep(i,L){
       int nx = K[i] - '0';
       rep(j,D){
           dp[i+1][(j+nx)%D][0]+=dp[i][j][0];
           dp[i+1][(j+nx)%D][0]%=MOD;

           rep(k,nx){
               dp[i+1][(j+k)%D][1]+=dp[i][j][0];
               dp[i+1][(j+k)%D][1]%=MOD;
           }

           rep(k,10){
               dp[i+1][(j+k)%D][1]+=dp[i][j][1];
               dp[i+1][(j+k)%D][1]%=MOD;
           }
       }
   }
   cout << (dp[L][0][0]+dp[L][0][1]-1+MOD)%MOD << endl;
   
   return 0;
}
