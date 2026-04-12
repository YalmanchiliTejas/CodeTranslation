

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll N = 3e5+5;
vector<int>adj[N],adj1[N];
vector<pair<int,int>>v;
map<pair<int,int>,int>mp;
bool visited[N];
int height[N],val[N],grid[55][55];



void solve(){
 int n;
 cin>>n;
 ll a[n];
 for(int i=0;i<n;i++)cin>>a[i];
 ll pref[n];
 pref[0]=a[0];
 for(int i=0;i<n-1;i++){
    pref[i+1]=(pref[i]+a[i+1])%MOD;
 }
 ll ans=0;
 for(int i=1;i<n;i++){
    ll t=(pref[i-1]*a[i])%MOD;
    ans=(ans+t)%MOD;
 }
 cout<<ans;
}
int main(){
    int t=1;
    //cin>>t;
   while(t--)solve();
}
