#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
ll sum[51]={},p[51]={};
ll solve(ll n,ll x){
    if(n==0) return 1;
    if(x<=n) return 0;
    if(x<=sum[n]/2) return solve(n-1,x-1);
    if(x==sum[n]/2+1) return solve(n-1,x-1)+1;
    return p[n-1]+1+solve(n-1,x-sum[n]/2-1);
}
int main(void){
    ll n,x;
    cin>>n>>x;
    sum[0]=1,p[0]=1;
    for(int i=1;i<=50;i++){
        sum[i]=2*sum[i-1]+3;
        p[i]=2*p[i-1]+1;
    }
    cout<<solve(n,x)<<endl;
}