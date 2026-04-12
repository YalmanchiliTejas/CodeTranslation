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
#include <chrono>
#include <random>
#include <time.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
#define N 500000
ll MOD=1e9+7;
vector<vec> G(N,vec());
bool ans=false;
int dfs(int x,int p){
    int count=0;
    for(auto e:G[x]){
        if(e==p)continue;
        if(dfs(e,x)==0){
            count++;
        }
    }
    if(count>=2)ans=true;
    //cout<<x<<" "<<count<<endl;
    return count;
}
main(){
    int n=in();
    rep(i,n-1){
        int a=in(),b=in();
        G[a].pb(b);G[b].pb(a);
    }
    rep(i,100){
        int a=rand()%n+1;
        dfs(a,0);
    }
    cout<<(ans?"First":"Second");
    return 0;
}

