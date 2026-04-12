#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dp[10005][105][2][2];         // dp[x][y][a][b], using (x and y) to get b from a
int N;
string s;
int MOD;
int mod=int(1e9)+7;
ll fun(int idx, int d, int zero , int tight){
    if(idx==N){
        if(d==0 and zero==1) return 1;
        return 0;
    }
    if(dp[idx][d][zero][tight]!=-1) return dp[idx][d][zero][tight];
    ll ans=0;
    int ulim=9;
    if(tight) ulim=s[idx]-'0';
    for(int i=0;i<=ulim;i++){
        ans+=fun(idx+1,(d+i)%MOD,(zero or i!=0), (tight and i==ulim)?1:0)%mod;
    }
    return dp[idx][d][zero][tight]=ans%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string k;
    cin>>k;
    int d;
    cin>>d;
    MOD=d;
    s=k;
    N=s.size();
    memset(dp,-1,sizeof(dp));
    cout<<fun(0,0,0,1)<<"\n";
}