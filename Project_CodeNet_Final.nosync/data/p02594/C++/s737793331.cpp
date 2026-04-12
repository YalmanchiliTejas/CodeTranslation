#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
#define mp make_pair
#define pb push_back
#define se second
#define fi first
#define N 100007
ll a[200007];
//string a, b;
//ll dp[200007];
vector<ll> v[200007];
ll vis[200007];
ll cnt=0, ans=0, maxi=-1, m;

void dfs(ll node, ll cnt, ll maxi) {
    vis[node]=1;
    if(a[node]>0) cnt++;
    else cnt=0;
    maxi=max(maxi,cnt);
    if(v[node].size()==1 && node!=1) {
        if(maxi<=m) ans++;
        //maxi=-1;
        //return;
    }  
    for(int i=0;i<v[node].size();i++) {
        if(!vis[v[node][i]]) {
            dfs(v[node][i], cnt, maxi);
        }
    }
}
 
void solve() {
    ll i, j, k, l, test, n, q, x, y, z;
    cin>>n;
    if(n>=30) cout<<"Yes\n";
    else cout<<"No\n";
}
int main() { 
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0; 
}
