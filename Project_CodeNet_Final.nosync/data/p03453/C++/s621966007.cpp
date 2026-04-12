#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


   const static long long MOD = 1000000007;

    vector<long long> pow2;
    vector<long long> F;
    vector<long long> IF;

    long long norm(long long a) {
        a %= MOD;
        if (a < 0) {
            a += MOD;
        }
        return a;
    }

    long long inverse(long long a) {
        long long b = MOD;
        long long u = 0, v = 1;
        a = norm(a);
        while (a != 0) {
            long long d = b / a;
            b -= d * a;
            u -= d * v;
            swap(a, b);
            swap(u, v);
        }
        return norm(u);
    }

    long long powM(long long x, long long e) {
        long long res = 1;
        while (e > 0) {
            if (e & 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            e >>= 1;
        }
        return res;
    }

    void init(int n) {
        F.clear();
        F.resize(n + 1, 1);
        IF = F;
        pow2.clear();
        pow2.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = pow2[i - 1] * 2 % MOD;
        }

        for (int i = 1; i <= n; ++i) {
            F[i] = F[i - 1] * i % MOD;
        }
        IF[n] = inverse(F[n]);
        for (int i = n - 1; i > 0; --i) {
            IF[i] = IF[i + 1] * (i + 1) % MOD;
        }
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) {
            return 0;
        }
        long long res = F[n] * IF[r] % MOD * IF[n - r] % MOD;
        return res;
    }

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    --s, --t;

    vector<vector<pair<int,int>>> graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    const long long INF = 1LL << 60;

    auto dijkstra = [&](int s, vector<long long>& dis, vector<long long>& cnts) {
        dis.clear();
        dis.resize(n, INF);
        dis[s] = 0;
        using PII = pair<long long,int>;
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.emplace(0, s);
        cnts[s] = 1;

        while (!pq.empty()) {
            int u = pq.top().second;
            long long d = pq.top().first;
            pq.pop();
            if (d != dis[u]) {
                continue;
            }

            for (auto& e : graph[u]) {
                int v = e.first;
                long long w = e.second;
                if (dis[v] > d + w) {
                    dis[v] = d + w;
                    cnts[v] = cnts[u];
                    pq.emplace(dis[v], v);
                } else if (dis[v] == d + w) {
                    (cnts[v] += cnts[u]) %= MOD;
                }
            }
        }
    };

    vector<long long> disS(n, INF);
    vector<long long> disT(n, INF);
    vector<long long> cntS(n, 0);
    vector<long long> cntT(n, 0);
    dijkstra(s, disS, cntS);
    dijkstra(t, disT, cntT);

    // cout << cntS[t] << " " << cntT[s] << " " << disS[t] << endl;


    auto count = [&](int u, int v) {
        long long res = (cntS[u] * cntS[u]) % MOD;
        res *= (cntT[v] * cntT[v]) % MOD;
        res %= MOD;
        return res;
    };
    long long res = 0; 
    
    long long inv2 = (MOD + 1) / 2;
    {
        vector<int> mids;

        vector<bool> disabled(n, false);
        for (int i = 0; i < n; ++i) {
            if (disS[i] == disT[i] && disS[i] * 2 == disS[t]) {
                mids.push_back(i);
                disabled[i] = true;
            }
        }

        res = (cntS[t] * cntS[t]) % MOD;

        for (auto x : mids) {
            // cout << x << " " << cntS[x] << " " << cntT[x] << " " << endl;
            res += MOD - (cntS[x] * cntT[x]) % MOD * ((cntS[x] * cntT[x]) % MOD);
            res %= MOD;
        }
        
        long long D = disS[t];
        for (int i = 0; i < n; ++i) {
            int u = i;
            for (auto& e : graph[u]) {
                int v = e.first;
                if (v > u) {
                    if (disS[u] + e.second + disT[v] == D && disS[u] * 2 < D && disT[v] * 2 < D) {
                        res += MOD - count(u, v);
                        res %= MOD;
                    }
                    if (disS[v] + e.second + disT[u] == D && disS[v] * 2 < D && disT[u] * 2 < D) {
                        res += MOD - count(v, u);
                        res %= MOD;
                    }
                }
            }
        }
    }

    // (res *= inv2) %= MOD;
    cout << res << '\n';



    return 0;
}