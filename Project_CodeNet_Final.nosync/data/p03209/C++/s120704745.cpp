//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define FIX(a) ((a)%mod+mod)%mod
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define fi first
#define se second
#define pb push_back
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
ll nmax  = 50;
vll a(nmax+1), p(nmax+1);
ll solve(ll n, ll x){
    if(a[n]==x) return  p[n];
    if(x==0) return 0LL;
    if(n==0) return 1LL;
    if(x>=a[n-1]+2){
        return 1LL + solve(n-1, x-a[n-1]-2) + solve(n-1, a[n-1]);
    }else{
        return solve(n-1, x-1);
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,x;
    cin >> n >> x;
    REP(i,n+1){
        ll t = 1;
        t <<= (i+1);
        p[i] = t-1;
        t <<= 1;
        a[i] = t-3;
    }
    ll ans = solve(n, x);
    cout << ans << endl;
    return 0;
}