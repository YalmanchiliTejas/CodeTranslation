#include<bits/stdc++.h>
using namespace std;
typedef  long long  ll;
ll inf=1000000000000000000,mod=998244353;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x,m;cin>>n>>x>>m;
  	if(m==0){cout<<"0";return 0;}
    ll st=0,en=n-1,curr=x%m,sum=0,presum[m]={0},vis[m]={0},idx[m]={0},val;
    for(ll i=0;i<n;i++){
        if(vis[curr]){
            st=idx[curr];
            en=i-1;break;
        }
        vis[curr]=1;
        idx[curr]=i;
        // cout<<curr<<endl;
        presum[i]=curr;
        if(i)
        presum[i]+=presum[i-1];
        curr=(curr*curr)%m;
    }
    if(st-1>=0)
    val=presum[en]-presum[st-1];
    else
    val=presum[en];

    ll ans=0;
    if(st-1>=0){
    ans+=presum[st-1];
    n-=st;}
    // cout<<((n/(en-st+1))*val)<<" ";
    ans+=(n/(en-st+1))*val;
	n%=(en-st+1);
	if(n){
    ans+=presum[st+n-1];
    if(st-1>=0)
    ans-=presum[st-1];}
    cout<<ans;
}
