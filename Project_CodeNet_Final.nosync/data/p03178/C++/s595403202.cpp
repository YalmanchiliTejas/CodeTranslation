#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define endl '\n'

ll dp[10005][2][105];
ll d;
string k;
ll n;
ll mod = 1e9+7;
ll solve(ll u,ll f1,ll mask)
{
    //cout<<u<<" "<<f1<<" "<<mask<<endl;
    if(u==n){
        if(mask%d == 0)
        return 1;
        return 0;
    }

    if(dp[u][f1][mask]==-1){
        ll val = 0;
        if(f1==0){
            val = solve(u+1,0,(mask+(k[u]-'0'))%d);
            for(ll i=0;i<=9 and i<(k[u]-'0');i++){
                val = (val+solve(u+1,1,(mask+i)%d)+mod)%mod;
            }
        }
        else{

            for(ll i=0;i<=9;i++){
                val = (val+solve(u+1,1,(mask+i)%d)+mod)%mod;
            }

        }
        dp[u][f1][mask] = val;
    }
    return dp[u][f1][mask];


}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>k;
    cin>>d;
    n = k.size();
    ll ans = 0;

    cout<<(mod+solve(0,0,0)-1)%mod<<endl;

}
