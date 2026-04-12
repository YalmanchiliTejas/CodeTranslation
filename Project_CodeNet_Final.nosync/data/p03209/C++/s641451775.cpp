#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int n;
ll x;
ll h[51],p[51];
ll dfs(ll n,ll x){
    if(n==0&&x>0) return 1;
    if(n==0&&x<=0) return 0;
    if(x<=h[n-1]+1) return dfs(n-1,x-1);
    return dfs(n-1,x-h[n-1]-2)+p[n-1]+1;
}
int main(){
    cin>>n>>x;
    h[0]=1,p[0]=1;
    FOR(i,1,n){
        h[i]=h[i-1]*2+3;
        p[i]=p[i-1]*2+1;
    }
    cout<<dfs(n,x)<<endl;
    return 0;
}