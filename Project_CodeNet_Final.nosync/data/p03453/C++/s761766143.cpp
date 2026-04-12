#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 1000000007;
int INF = 1e18;
vector<vector<int> > data;
vector<vector<int> > money;
signed main() {
    ios_base::sync_with_stdio(false);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    for (int i=0; i < n; i++){
        vector<int> h1, h2;
        data.push_back(h1);
        money.push_back(h2);
    }
    for (int i=0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        data[a-1].push_back(b-1);
        data[b-1].push_back(a-1);
        money[b-1].push_back(c);
        money[a-1].push_back(c);
    }
    vector<int> ans_s(n), p_s(n);
    fill(ans_s.begin(), ans_s.end(), INF);
    fill(p_s.begin(), p_s.end(), 0);
    ans_s[s] = 0;
    p_s[s] = 1;
    set<pair<int, int> > ms;
    for (int i=0; i < n; i++) ms.insert(make_pair(ans_s[i], i));
    for (int i=0; i < n; i++){
        pair<int, int> p = *ms.begin();
        ms.erase(ms.begin());
        int V = p.second;
        for (int j=0; j < data[V].size(); j++){
            int to = data[V][j];
            if (ans_s[to] <= ans_s[V]) continue;
            ms.erase(ms.upper_bound(make_pair(ans_s[to], to-1)));
            int R = ans_s[V] + money[V][j];
            if (R < ans_s[to]){
                ans_s[to] = R;
                p_s[to] = p_s[V];
            }
            else if (R == ans_s[to]){
                p_s[to] += p_s[V];
                p_s[to] %= MOD;
            }
            ms.insert(make_pair(ans_s[to], to));
        }
    }
    vector<int> ans_t(n), p_t(n);
    fill(ans_t.begin(), ans_t.end(), INF);
    fill(p_t.begin(), p_t.end(), 0);
    ans_t[t] = 0;
    p_t[t] = 1;
    ms.clear();
    for (int i=0; i < n; i++) ms.insert(make_pair(ans_t[i], i));
    for (int i=0; i < n; i++){
        //cout << i << endl;
        pair<int, int> p = *ms.begin();
        ms.erase(ms.begin());
        int V = p.second;
        for (int j=0; j < data[V].size(); j++){
            int to = data[V][j];
            if (ans_t[to] <= ans_t[V]) continue;
            ms.erase(ms.upper_bound(make_pair(ans_t[to], to-1)));
            int R = ans_t[V] + money[V][j];
            if (R < ans_t[to]){
                ans_t[to] = R;
                p_t[to] = p_t[V];
            }
            else if (R == ans_t[to]){
                p_t[to] += p_t[V];
                p_t[to] %= MOD;
            }
            ms.insert(make_pair(ans_t[to], to));
        }
    }
    int res = p_s[t] * p_s[t];
    res %= MOD;
    int K = ans_s[t];
    for (int i=0; i < n; i++){
        if (ans_s[i] + ans_t[i] != K || ans_s[i] != ans_t[i]) continue;
        int X = p_s[i] * p_t[i];
        X %= MOD;
        res -= X*X;
        res %= MOD;
    }
    for (int i=0; i < n; i++){
        for (int j=0; j < data[i].size(); j++){
            int to = data[i][j];
            if (ans_s[i] + money[i][j] + ans_t[to] != K) continue;
            if (ans_s[i] >= ans_t[i]) continue;
            if (ans_s[to] <= ans_t[to]) continue;
            int X = p_s[i] * p_t[to];
            X %= MOD;
            res -= X*X;
            res %= MOD;
        }
    }
    res += MOD;
    cout << res%MOD << endl;
    return 0;
}








