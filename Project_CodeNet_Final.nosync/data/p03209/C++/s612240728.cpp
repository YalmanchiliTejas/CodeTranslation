#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

ll N,X;
ll L[51],P[51];

ll dfs(ll n,ll x){
    if(n==0) return P[0];
    if(x==1) return 0;
    if(x<=1+L[n-1]) return dfs(n-1,x-1);
    if(x==1+L[n-1]+1) return P[n-1]+1;
    if(x<=1+L[n-1]+1+L[n-1]) return P[n-1]+1+dfs(n-1,x-(1+L[n-1]+1));
    if(x==1+L[n-1]+1+L[n-1]+1) return P[n];
}

int main(){
    L[0]=1,P[0]=1;
    cin>>N>>X;

    repn(i,N){
        L[i]=2*L[i-1]+3;
        P[i]=2*P[i-1]+1;
    }

    ll ans=dfs(N,X);
    cout<<ans<<endl;
}