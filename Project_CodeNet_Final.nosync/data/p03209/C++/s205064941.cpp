#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define rep(i,n) for(ll i=0;i<n;i++)
#define INF 1e9+7
#define LLINF 1e18
using namespace std;
const ll MOD = 1e9 +7;

ll n,x;
ll l[51],p[51];

ll res(ll a,ll b){
    if(b==0) return 0;
    if(a==0) return 1;
    ll ans=0;
    if(b<=l[a-1]+1){
        ans=res(a-1,b-1);
    }
    else if(b==l[a-1]+2){
        ans=(p[a-1]+1);
    }
    else{
        ans=(p[a-1]+res(a-1,b-2-l[a-1])+1);
    }
    return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>x;
    l[0]=1,p[0]=1;
    rep(i,n){
        l[i+1]=l[i]*2+3;
        p[i+1]=p[i]*2+1;
    }
    cout <<res(n,x)<<endl;
    return 0;
}