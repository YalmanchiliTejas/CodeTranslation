#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void solve() {
    ll N;
    cin >> N;
    Vl cnts(26, L_INF);
    Vl tmps;
    for (ll i = 0; i < N; i++) {
        string s;
        cin >> s;
        tmps.assign(26, 0);
        for (const auto& c : s) {
            ++tmps[c - 'a'];
        }
        for (ll j = 0; j < 26; j++) {
            cnts[j] = min(cnts[j], tmps[j]);
        }
    }

    string ans;
    for (ll i = 0; i < 26; i++) {
        char c = (char)('a' + i);
        if (cnts[i] != L_INF) {
            for (ll j = 0; j < cnts[i]; j++) {
                ans += c;
            }
        }
    }

    cout << ans << "\n";
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif
#ifdef FILEOUTPUT
    ofstream ofs("./in_out/output.txt");
    cout.rdbuf(ofs.rdbuf());
#endif
    solve();
    cout << flush;
    return 0;
}