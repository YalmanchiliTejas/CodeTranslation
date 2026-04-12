#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define mod 1000000007

vector <ll> ad[200006];
vector <ll> vis(200006,0);

ll ans=0, n, m, k;


void add(ll x, ll y){
    ad[x].push_back(y);
    ad[y].push_back(x);
}

ll dfs(ll node){
    vis[node]=1;
    ++ans;
    for(ll i:ad[node]){
        if(!vis[i])
            dfs(i);
    }
    return ans;
}

void solve(){
    cin>>n;
   ll a;
   ll sum=0,ans=0;
   for(ll i=0;i<n;i++){
    cin>>a;
   if(i){
    ans=(ans+((sum*a)%mod))%mod;
   }
    sum=(sum+a)%mod;
   }
   cout<<ans<<endl;


}

int main(){
    solve();
    return 0;
}