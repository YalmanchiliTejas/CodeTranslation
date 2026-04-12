#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll n, m, a, b, c[10], res;
vector<ll> vec[10];

void dfs(ll x, ll y){
    if (x == n) {
        res++;
    } else {
        c[y] = 1;
        for (ll i = 0; i < vec[y].size(); i++) {
            if (c[vec[y][i]]) continue;
            dfs(x + 1, vec[y][i]);
        }
        c[y] = 0;
    }
}

int main(void){
    // Your code here!
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(1, 1);
    cout << res << endl;
}
