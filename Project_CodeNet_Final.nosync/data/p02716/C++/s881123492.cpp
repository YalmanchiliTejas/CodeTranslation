#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define ull         unsigned long long
#define pb          push_back
#define pii         pair<int,int>
#define pll         pair<long,long>
#define vi          vector<int>
#define vll         vector<ll>
#define vii         vector<pii>
#define Mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define rall(a)      (a).rbegin(),(a).rend()
#define ff           first
#define ss           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define mod        1000000007
//#define mod        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rem(i,a,b)  for(int i=a;i>b;i--)
#define mp(a,b)     make_pair(a,b)
#define INF         numeric_limits<ll>::max();
#define NINF        numeric_limits<ll>::min();
#define vvi(a,b,name)    vector<vector<int>> name(a,vector<int>(b,-1))
const long double pi=3.14159265359;

inline ll add(ll a,ll b,ll m){
    if((a+b)>=m)return (a+b)%m;
    return a+b;
}

inline ll mul(ll a,ll b,ll m){
    if((a*b)<m)return a*b;
    return (a*b)%m;
}

int n;
ll a[200005];
map<pair<int,int>,ll> dp;

ll go(int i,int j){
    if(j>(i+1)/2)return NINF+mod;

    if(i<1 || j<1 )return 0;

    if(dp.find({i,j})!=dp.end())return dp[{i,j}];

    return dp[{i,j}]=max(go(i-2,j-1)+a[i],go(i-1,j));

}

void solve(){
    int n;cin>>n;
    rep(i,1,n+1)cin>>a[i];
    cout<<go(n,n/2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
