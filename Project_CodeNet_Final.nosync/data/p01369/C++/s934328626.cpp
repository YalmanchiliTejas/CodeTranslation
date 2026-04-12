#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define all(x) begin(x),end(x)

#define dump(x) cerr<<#x<<" = "<<(x)<<endl
#define debug(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

template<class T>
ostream &operator<<(ostream &os, const vector <T> &v) {
    os << "[";
    REP (i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

template<class T, class U>
ostream &operator<<(ostream &os, const pair <T, U> &p) {
    return os << "(" << p.first << " " << p.second << ")";
}

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector <vector<int>>;
using vvll = vector <vector<ll>>;

#define inf(T) (numeric_limits<T>::max() / 2)
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    vector<char> left{'q', 'w', 'e', 'r', 't',
                      'a', 's', 'd', 'f', 'g',
                      'z', 'x', 'c', 'v', 'b'};
    vector<char> right{'y', 'u', 'i', 'o', 'p',
                       'h', 'j', 'k', 'l', 'n', 'm'};

    map<char,int> pos;
    for (char c : left) pos[c] = 0;
    for (char c : right) pos[c] = 1;

    for (;;) {
        string str; cin >> str;
        if (str == "#") break;

        int prev = -1;
        int ans = -1;
        for (char c : str) {
            if (prev != pos[c]) ++ans;
            prev = pos[c];
        }

        cout << ans << endl;
    }

    return 0;
}

