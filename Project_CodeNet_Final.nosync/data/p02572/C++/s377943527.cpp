#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long int
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pci pair<char,int
#define mii map<int,int>
#define mll map<long long int,long long int>
#define mci map<char,int>
#define umii unordered_map<int,int>
#define umll unordered_map<long long int,long long int>
#define umci unordered_map<char,int>
#define F first
#define S second
#define pb push_back
#define endl '\n'
#define mod 1000000007
using namespace std;
//ll visit[100001]={0};
//vector<ll> adj[1000001];

    
int main(){
   IOS;
int t;t=1;//cin>>t;
while(t--){
ll n;cin>>n;
ll a[n];
for(ll i=0;i<n;i++) cin>>a[i];
ll ans=0;
ll suf[n];
suf[n-1]=a[n-1];
for(ll j=n-2;j>=0;j--){
    suf[j]=(a[j]+suf[j+1])%mod;
}
for(ll i=0;i<n-1;i++){
    ans=(ans+(a[i]*suf[i+1])%mod)%mod;
}
cout<<ans;
}
    
    

    
    





return 0;}
