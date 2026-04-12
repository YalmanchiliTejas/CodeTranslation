#include <bits/stdc++.h>
using namespace std;

#define Art Code
#define Artist Shivam Gupta
#define MoT This Art belongs to Artist
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long int
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vl(p) vector<p>
#define W while
#define For(i,s,x) for(i=s;i<x;i++)
#define Fore(i,s,x) for(i=s;i<=x;i++)
#define FoR(i,s,x) for(i=s-1;i>=x;i--)
#define ForE(i,s,x) for(i=s;i>=x;i--)
#define all(v) v.begin(),v.end()
#define pb push_back
#define in insert
#define sz size()
#define F first
#define S second
#define nl cout<<"\n"
#define pr(a) cout<<a<<" "
#define pr2(a,b) cout<<a<<" "<<b<<"\n"
#define pr3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n"
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define mod 1000000007
#define MAX 200005

ll n, m;
vll a;
vl(vl(pll)) dp;

pll solve(ll i, ll j) {
    if(dp[i][j].F!=-1) return dp[i][j];
    if(i==j) return dp[i][j]={a[i],0};
    pll x=solve(i,j-1), y=solve(i+1,j);
    pll A={x.S+a[j],x.F}, B={a[i]+y.S,y.F};
    dp[i][j] = A.F>B.F ? A:B;
    return dp[i][j];
}



int main() {
    FASTIO;
    ll t=1, i, j, k, l;
    // cin>>t;
    W(t--) {
        cin>>n;
        a.resize(n+1);
        dp.resize(n+1); Fore(i,1,n) dp[i].resize(n+1);
        Fore(i,1,n) Fore(j,1,n) dp[i][j].F=-1;
        Fore(i,1,n) cin>>a[i];
        pll ans=solve(1,n);
        // Fore(i,1,n) { Fore(j,1,n) pr(dp[i][j].F), pr(dp[i][j].S), pr('-'); nl; }
        pr(ans.F-ans.S);
        nl;
    }
    return 0;
}