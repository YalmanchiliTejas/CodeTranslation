#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define trav(a, x) for (auto& a : x)
using ull = uint64_t;
using ll = int64_t;
using PII = pair<int, int>;
using VI = vector<int>;
#define INF (1ll<<60)

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(A v) {
bool first = true; string res = "{";
for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); }
res += "}"; return res; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H); debug_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N;
    string s;
    cin >> N >> s;
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
            vector<int> V(N, -1);
            V[0] = j;
            V[N-1] = k;
            int last = -1;
            FOR(i, 0, N-2) {
                if (i == N - 2) {
                    if (V[i] == 0) {
                        if (s[i] == 'o') {
                            last = V[(i-1+N) % N];
                        } else {
                            last = 1 - V[(i-1+N) % N];
                        }
                    } else {
                        if (s[i] == 'o') {
                            last = 1 - V[(i-1+N) % N];
                        } else {
                            last = V[(i-1+N) % N];
                        }
                    }
                    break;
                }
                if (V[i] == 0) {
                    if (s[i] == 'o') {
                        V[i+1] = V[(i-1+N) % N];
                    } else {
                        V[i+1] = 1 - V[(i-1+N) % N];
                    }
                } else {
                    if (s[i] == 'o') {
                        V[i+1] = 1 - V[(i-1+N) % N];
                    } else {
                        V[i+1] = V[(i-1+N) % N];
                    }
                }
            }
            if (last == V[N-1]) {
                string ans1;
                REP(i, N) {
                    if (V[i] == 1) ans1.pb('W');
                    else ans1.pb('S');
                }
                if (s[N-1] == 'o') {
                    if (V[N-1] == 0 && (V[N-2] == V[0])) {
                        cout << ans1 << endl;
                        return 0;
                    }
                    if (V[N-1] == 1 && (V[N-2] != V[0])) {
                        cout << ans1 << endl;
                        return 0;
                    }
                }
                if (s[N-1] == 'x') {
                    if (V[N-1] == 0 && (V[N-2] != V[0])) {
                        cout << ans1 << endl;
                        return 0;
                    }
                    if (V[N-1] == 1 && (V[N-2] == V[0])) {
                        cout << ans1 << endl;
                        return 0;
                    }
                }
                // cout << ans1 << endl;
                // return 0;
            }
        }

    }
    cout << -1 << endl;
}