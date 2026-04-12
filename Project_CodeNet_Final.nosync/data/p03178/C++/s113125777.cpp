#include <bits/stdc++.h>
#define ll long long
#define name "loz"
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ini freopen(name".inp","r",stdin);
#define ii pair<int,int>
using namespace std;

const double PI = acos(-1);
const ll INF = 1e9;
const int MOD = 1e9+7;
const int MAXK = 1e4+5, MAXD = 100;
int dp[MAXK][2][MAXD];

int main(){
    fastio
    int d; string k;
    cin>>k>>d; int n=k.size();
    dp[0][0][0]=1;
    for (int i=1; i<=n; i++){
        for (int mod=0; mod<d; mod++){
            for (int lss=0; lss<=1; lss++){
                for (int x=0; x<10; x++){
                    if (x>k[i-1]-'0'&&!lss) break;
                    dp[i][(x<k[i-1]-'0'||lss)][(mod+x)%d]+=dp[i-1][lss][mod];
                    dp[i][(x<k[i-1]-'0'||lss)][(mod+x)%d]%=MOD;
                    //cout<<(x<k[i-1]-'0'||lss)<<' '<<(mod+x)%d<<'\n';
                }
            }
        }
    }
    cout<<(dp[n][0][0]+dp[n][1][0]>0?(dp[n][0][0]+dp[n][1][0]-1)%MOD:MOD-1);
    return 0;
}
