#include <bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
ll dp[10001][2][101];
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string k;
cin>>k;
int d;
cin>>d;
dp[0][0][0]=1;
for(int i=0;i<k.size();i++){
     int tmp=k[i]-'0';
     for(int j=0;j<2;j++){
      for(int l=0;l<d;l++){
         for(int r=0;r<(j?10:tmp+1);r++){
             (dp[i+1][j||(j!=1&&tmp!=r)][(l+r)%d]+=dp[i][j][l])%=mod;
            }
        }
     }
 }
cout<<(dp[k.size()][0][0]+dp[k.size()][1][0]-1+mod)%mod <<endl;
}
