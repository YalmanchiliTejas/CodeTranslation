#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(a)-1;i>=b;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define printV(v) for(auto x : v){cout << x << " ";} cout << endl
#define printVS(vs) for(auto x : vs){cout << x << endl;}
#define printVV(vv) for(auto v : vv){for(auto&& x : v){cout << x << " ";}cout << endl;}
#define printP(p) cout << p.first << " " << p.second << endl
#define printVP(vp) for(auto p : vp) printP(p);

typedef long long ll;
typedef pair<int, int> Pii;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<Pii> vp;
typedef vector<vector<int>> Graph;
const int inf = 1e9;
const int mod = 1e9 + 7;

vector<string> getBoard(string s) {
    vector<string> t;
    stringstream ss(s);
    string line;
    while (getline(ss, line, '/')) {
        string temp = "";
        for (auto c : line) {
            if (c == 'b') {
                temp += 'b';
            } else {
                rep(i, c - '0') temp += '.';
            }
        }
        t.emplace_back(temp);
    }
    return t;
}

string make(vector<string> t) {
    string s = "";
    int cnt = 0;
    for (auto l : t) {
        cnt++;
        int n = 0;
        for (auto c : l) {
            if (c == 'b') {
                if (n > 0) {
                    s += n + '0';
                    n = 0;
                }
                s += 'b';
            } else {
                n++;
            }
        }
        if (n > 0) {
            s += n + '0';
            n = 0;
        }
        if (cnt < t.size()) s += '/';
    }

    return s;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    string s;
    while (cin >> s, s[0] != '#') {
        auto t = getBoard(s);

        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        swap(t[a][b], t[c][d]);

        cout << make(t) << endl;
    }

}