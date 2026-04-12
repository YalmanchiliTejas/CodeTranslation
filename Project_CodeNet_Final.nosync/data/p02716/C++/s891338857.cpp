#include<bits/stdc++.h>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    else return gcd(b,a%b);
}
vector<ll>A(200010);
vector<vector<ll> >dp(200010,vector<ll>(3,-inf*inf));
ll solve1(ll a,ll b){
    if(dp[a][b]!=-inf*inf){
        return dp[a][b];
    }
    ll res=A[a];
    if(b==0){
        res+=max(solve1(a+2,b),max(solve1(a+3,b+1),solve1(a+4,b+2)));
    }else if(b==1){
        res+=max(solve1(a+2,b),solve1(a+3,b+1));
    }else{
        res+=solve1(a+2,b);
    }
    dp[a][b]=res;
    return res;
}
ll solve2(ll a,ll b){
    if(dp[a][b]!=-inf*inf){
        return dp[a][b];
    }
    ll res=A[a];
    if(b==0){
        res+=max(solve2(a+3,b+1),solve2(a+2,b));
    }else if(b==1){
        res+=solve2(a+2,b);
    }
    dp[a][b]=res;
    return res;
}

signed main(){
    ll n;cin>>n;
    rep(i,n)cin>>A[i];
    if(n%2==0){
        ll ans;
        dp[n-1][1]=A[n-1];
        dp[n-2][0]=A[n-2];
        ans=max(solve2(0,0),solve2(1,1));
        cout<<ans<<endl;
    }else{
        ll ans;
        dp[n-1][2]=A[n-1];
        dp[n-2][1]=A[n-2];
        dp[n-3][0]=A[n-3];
        ans=max(solve1(0,0),max(solve1(1,1),solve1(2,2)));
        cout<<ans<<endl;
    }
}