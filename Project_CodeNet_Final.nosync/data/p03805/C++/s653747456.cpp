#include <bits/stdc++.h>

using namespace std;

/*  テンプレここから */
typedef long long ll;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i, start, end) for(int i = start; i < end; i++)
#define all(x) (x).begin(), (x).end()
#define INF (1e9)
#define add_mod(a, b, x) ( (ll)(a) + (ll)(b) ) % (ll)(x)
#define mul_mod(a, b, x) ( ((ll)(a) % (ll)(x)) * ((ll)(b) % (ll)(x)) ) % (ll)(x)
#define out(x) cout << (x) << endl;
#define outyes(bool_val) cout << (bool_val ? "yes" : "no") << endl;
#define outYes(bool_val) cout << (bool_val ? "Yes" : "No") << endl;
#define outYES(bool_val) cout << (bool_val ? "YES" : "NO") << endl;
#define outPossible(bool_val) cout << (bool_val ? "Possible" : "Impossible") << endl;
#define outPOSSIBLE(bool_val) cout << (bool_val ? "POSSIBLE" : "IMPOSSIBLE") << endl;

ll sub_mod(ll a, ll b, ll x){
    ll tmp = (a - b) % x;
    if(tmp < 0) tmp += x;
    return tmp;
}
ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
/*  テンプレここまで */

vector<vector<int>> graph(10, vector<int>());
int n, m, cnt = 0;

void search(int i, vector<int> visited){
    visited[i] = 1;
    for(auto itr = graph[i].begin(); itr != graph[i].end(); ++itr){
        if(visited[*itr] == 0){
            if(accumulate(all(visited), 0) == n-1){
                ++cnt;
                return;
            }
            search(*itr, visited);
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    rep(i, m){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(n + 1, 0);
    search(1, visited);

    cout << cnt << endl;
}