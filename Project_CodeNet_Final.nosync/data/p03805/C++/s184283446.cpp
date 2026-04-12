#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const ll mod=1000000007;

ll n,m;
vector<ll> v[9];
bool seen[9]={};
ll ans=0;

void dfs(ll x,ll k){
    if(k==n){
        ans++;
        return;
    }
    seen[x]=true;
    for(auto z:v[x]){
        if(!seen[z]){
            dfs(z,k+1);
        }
    }
    seen[x]=false;
}

int main() {
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,1);
    cout<<ans<<endl;
}
