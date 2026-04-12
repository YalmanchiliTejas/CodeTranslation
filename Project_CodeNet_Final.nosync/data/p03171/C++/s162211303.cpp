#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define MAX_V 400010
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
template<typename A, size_t NNN, typename T>
void Fill(A (&array)[NNN], const T &val){
    fill( (T*)array, (T*)(array+NNN), val );
}
#define INF 1e9+7
#define LLINF 1e18+7
ll MOD=1e9+7;
#define N 610000
ll n,m,k;
double dp[400][400][400];
ll a[N];
ll b[N];
int mp[2000][2000];
bool visited[4000][4000];
ll mem[4000][4000];
ll dfs(int x,int y){
    if(visited[x][y]){
        return mem[x][y];
    }
    visited[x][y]=1;
    if(x>y||y<x)return (ll)0;
    if((n-(y-x))%2){
        ll aa=dfs(x+1,y)+a[x],bb=dfs(x,y-1)+a[y];
        aa=max(aa,bb);
        return mem[x][y]=aa;
    }
    else{
        ll aa=dfs(x+1,y)-a[x],bb=dfs(x,y-1)-a[y];
        aa=min(aa,bb);
        return mem[x][y]=aa;
    }
}
int main(){
    n=in();
    rep(i,n)a[i]=lin();
    cout<<dfs(0,n-1);
    return 0;
}