/*#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<cstdio>
#include<stack>
#include<queue>
#include<fstream>
#include<cstdio>
#include<deque>
#include<iomanip>
#include <numeric>*/
#include<bits/stdc++.h>

using namespace std;
#define ok1 printf("ok1\n");
#define ok2 printf("ok2\n");
#define M 1000000000000000000LL
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);(i)--)
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define pf push_front
#define MIN(a,b) a=min((a),(b))
#define MAX(a,b) a=max((a),(b))
#define SIZE(v) (int)v.size()
const double pi = acos(-1.0);

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef deque<ll> dll;
typedef pair<ll, ll> P;
typedef vector<P> vP;
const ll mod = 1e9 + 7;
ll dx[4] = {1,0,-1,0};
ll dy[4] = {0,1,0,-1};
vvll g(10,vll(10,0));
ll dfs(ll v,ll n,vector<bool> vis){
    bool all_v = true;
    rep(i,n) if(!vis[i]) all_v = false;
    if(all_v) return 1;
    int ret=0;
    rep(i,n){
        if(!g[v][i]) continue;
        if(vis[i]) continue;

        vis[i]=true;
        ret += dfs(i,n,vis);
        vis[i] = false;
    }
    return ret;
}

int main(){
    ll n,m;
    cin >> n >> m;
    vll a(m),b(m);
    rep(i,m) {
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        g[a[i]][b[i]] = 1;
        g[b[i]][a[i]] = 1;
    }
    vector<bool> c(n,false);
    c[0]=true;
    cout << dfs(0,n,c) << endl;;
    return 0;
}  
