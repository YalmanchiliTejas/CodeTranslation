#include <bits/stdc++.h>

#define endl '\n'
#define PB push_back
#define PF push_front
#define MP make_pair
#define fi first
#define se second
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 14;

vector<ll> cycle;
vector<bool> used;

void dfs(ll v, ll m) {
    cycle.PB(v);
    if (used[v]) {
        return;
    }
    used[v] = 1;
    ll to = (v * v) % m;
    dfs(to, m);
}

int main(){
    ios_base::sync_with_stdio(false); //cin.tie(nullptr); cout.tie(nullptr);
    ll n, x, m;
    cin >> n >> x >> m;
    used.assign(m, 0);
    dfs(x, m);
    ll pos = 0;
    for (; cycle[pos] != cycle.back() && pos < int(cycle.size()); pos++);
    pos ++;
    ll len = cycle.size() - pos;
    ll rem = (n - pos) % len;
    
    ll sum = 0;
    for (int i = pos; i < cycle.size(); i++) {
        sum += cycle[i];
    }

    ll ans = ((n - pos) / len) * sum;
    
    for (int i = 0; i < pos; i++) {
        ans += cycle[i];
    }

    for (int i = pos; i < pos + rem; i++) {
        ans += cycle[i];
    }
    
    cout << ans;
    return 0;
} 
