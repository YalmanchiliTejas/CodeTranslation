#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
ll N;
vector<ll> paths[100500];
ll dist[3][100500];

void dfs(int idx, int now, int from) {
    for(auto to : paths[now]) {
        if(to == from) continue;
        dist[idx][to] = dist[idx][now] + 1;
        dfs(idx, to, now);
    }
}

ll imos[100500];
ll OK[100500];

int main() {
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    dist[0][0] = 0;
    dfs(0, 0, -1);
    ll c[2];
    c[0] = 0;
    for(int i = 0; i < N; i++) {
        if(dist[0][i] > dist[0][c[0]]) c[0] = i;
    }
    dist[0][c[0]] = 0;
    dfs(0, c[0], -1);
    c[1] = 0;
    for(int i = 0; i < N; i++) {
        if(dist[0][i] > dist[0][c[1]]) c[1] = i;
    }
    dfs(1, c[1], -1);
    ll d = dist[1][c[0]];
    for(int i = 0; i < N; i++) {
        if(dist[0][i] + dist[1][i] == d) continue;
        //cerr << i << endl;
        vector<ll> tmp(3);
        tmp[0] = (dist[0][i] + dist[1][i] - d) / 2;
        tmp[1] = dist[0][i] - tmp[0];
        tmp[2] = dist[1][i] - tmp[0];
        sort(tmp.begin(), tmp.end());
        //cerr << tmp[0] << " " << tmp[1] << " " << tmp[2] << endl;
        do {
            ll now = min(tmp[1], tmp[2]);
            imos[tmp[0] + now]++;
            if(now == tmp[0]) {
                OK[now+tmp[0]]--;
            }
        } while(next_permutation(tmp.begin(), tmp.end()));
    }
    for(int i = 1e5; i >= 0; i--) {
        imos[i] += imos[i+1];
    }
    string ans;
    for(int i = 0; i < N; i++) ans.push_back('1');
    for(int i = 3; i <= N; i++) {
        if(imos[i] + OK[i] > 0) {
            ans[i-1] = '0';
        }
    }
    cout << ans << endl;
    return 0;
}
