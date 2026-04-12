#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef pair<int, int> Pii;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
typedef vector<vector<int>> Graph;
const int inf = 1e9;
const int mod = 1e9 + 7;

vector<string> parse(const string& s) {
    // stringstream ss("#" + s);
    stringstream ss(s);
    string t;
    vector<string> ret;
    while (getline(ss, t, '/')) {
        ret.emplace_back(t);
    }
    ret.back() += "@";  // "@" is added at the end of filename
    return ret;
}

// void dispVecStr(const vector<string>& vs) {
//     for (auto s : vs) {
//         cout << s << ",";
//     }
//     cout << endl;
// }

bool match(const vector<string>& vs, const vector<string>& vt) {
    if (vt.size() < vs.size()) return false;
    rep(i, vs.size()) {
        if (vs[i] != vt[i]) return false;
    }
    return true;
}

bool exist(const vector<string>& vs, const vector<vector<string>>& paths) {
    for (const auto& vt : paths) {
        if (match(vs, vt)) return true;
    }
    return false;
}

// if connot be restored, return an empty vector
vector<string> restore(const vector<string>& vs, const vector<vector<string>>& paths) {
    vector<string> ret;
    for (const auto& s : vs) {
        if (s == ".") {
            continue;
        } else if (s == "..") {
            // if (ret.back() == "#") return {};
            if (ret.empty()) return {};
            ret.pop_back();
        } else {
            ret.emplace_back(s);
            if (!exist(ret, paths)) return {};
        }
    }
    return ret;
}

void solve(int N, int M) {
    vector<vector<string>> paths;
    rep(i, N) {
        string s;
        cin >> s;
        paths.emplace_back(parse(s));
    }

    // queries
    rep(_, M) {
        vector<vector<vector<string>>> cand(2);
        rep(i, 2) {
            string s;
            cin >> s;
            if (s.back() == '/') {
                cand[i].emplace_back(parse(s + "index.html"));
            } else {
                cand[i].emplace_back(parse(s));
                cand[i].emplace_back(parse(s + "/index.html"));
            }
        }

        auto answer = [&]() {
            bool notfound = true;
            for (auto vs1 : cand[0]) {
                for (auto vs2 : cand[1]) {
                    auto vs = restore(vs1, paths);
                    auto vt = restore(vs2, paths);
                    if (!vs.empty() && !vt.empty()) {
                        notfound = false;
                        if (vs == vt) {
                            return "yes";
                        }
                    }
                }
            }
            return notfound ? "not found" : "no";
        };

        cout << answer() << endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M;
    while (cin >> N >> M, N) {
        solve(N, M);
    }
}