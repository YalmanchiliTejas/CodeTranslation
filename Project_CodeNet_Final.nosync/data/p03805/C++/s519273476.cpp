#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for (int i = s; i < (int)(n); i++)
using ll = long long;
using pll = pair<ll,ll>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
using vstr = vector<string>;
const ll MOD=1000000007;
vll dx{0,1,0,-1};
vll dy{1,0,-1,0};
int i,j,k,n,m,a,b,c;
ll res,ans;
vvll graph;

bool all(const vector<bool> &A)
{
    bool res=true;
    rep(i,0,A.size())res=res&&A[i];
    return res;
}

void dfs(ll v,vector<bool> seen) {
    seen[v] = true; 
    if(all(seen)){
        res+=1;
        return;
    }
    for (auto next_v : graph[v]) { 
        if (seen[next_v]) continue;
        dfs(next_v,seen);
    }
    return;
}

template <class type> void printVector(vector<type> vec){
    stringstream ss;
    ll n=vec.size();
    for(ll i=0;i<n;i++)
    {
        ss<<vec[i]<<" ";
        if(i!=n-1)ss<<" ";
    }
    cout<<ss.str()<<endl;
}

template <class type> void inputVector(vector<type>& vec){
    for(ll i=0;i<vec.size();i++)
    {
        cin>>vec[i];
    }
}

void solve(){
    cin >> n >> m;
    graph=vvll(n);
    rep(i,0,m){
        cin>>a>>b;a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    dfs(0,vector<bool>(n));
    cout<<res;
}

int main(){
    solve();
    return 0;
}
