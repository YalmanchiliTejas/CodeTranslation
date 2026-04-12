#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF (ll)1<<62
#define MAX 510000
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
#define uni(q) unique(all(q)),q.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;

vvl G(10);
bool visit[10];
ll cnt = 0;
ll n,m;

void dfs(ll u){
    if(visit[u]) return;
    visit[u] = true;
    for(auto v : G[u]){
        if(visit[v]) continue;
        dfs(v);
    }
    bool flag = true;
    rep(i,n){
        if(!visit[i]){
            flag = false;
            break;
        }
    }
    if(flag) cnt++;
    visit[u] = false;
}

int main(){
	cin >> n >> m;
    rep(i,m){
        ll a,b; cin >> a >> b;
        a--;  b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0);
    cout << cnt << endl;
}