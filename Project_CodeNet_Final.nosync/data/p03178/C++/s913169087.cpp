#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
#define pb push_back

using namespace std;
using ll=long long;
using pii= pair<int, int>;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
template<typename... T> void rd(T&... args) {((cin>>args), ...);}
template<typename... T> void wr(T... args) {((cout<<args<<" "), ...);cout<<endl;}

string s;
int D;
const int N=1e5+5,mod=1e9+7;
ll dp[N][105][2];

ll dfs(int i,int sum,bool strict){
    if(i==sz(s)) return sum==0;
    if(dp[i][sum][strict]!=-1) return dp[i][sum][strict];
    ll ret=0;
    int mx=9;
    if(strict) mx=s[i]-'0';
    for(int j=0;j<=mx;j++){
        (ret+=dfs(i+1,(sum+j)%D,j==mx&&strict))%=mod;
    }
    return dp[i][sum][strict]=ret;
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s>>D;
    memset(dp,-1,sizeof(dp));
    cout<<(dfs(0,0,1)-1+mod)%mod;
    return 0;
}

