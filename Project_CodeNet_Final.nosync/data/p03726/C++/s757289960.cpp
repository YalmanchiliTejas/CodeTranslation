/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
vector<ll> tree[100010];
ll child[100010] = {};
bool win = false;
ll N;

void dfs(ll cur, ll par){
    child[cur] = 1;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs(e, cur);
        child[cur] += child[e];
    }
}

void dfs2(ll cur, ll par){
    ll cnt = 0;
    for(auto &e: tree[cur]){
        if(child[e] % 2 == 1) cnt++;
    }
    if(cnt >= 2) win = true;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        ll tmp = child[e];
        child[cur] -= child[e];
        child[e] = N;
        dfs2(e, cur);
        child[e] = tmp;
        child[cur] += child[e];
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;

    rep(i,0,N-1){
        ll a,b;
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(0, -1);
    dfs2(0,-1);
    if(win){
        print("First");
    }else{
        print("Second");
    }
    
    

}