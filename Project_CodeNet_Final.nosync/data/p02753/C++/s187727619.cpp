#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <sstream>
#include <cmath>
#include <functional>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define reps(s,i,n) for(int i=s;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define skip(i,n,p) for(int i=0;i<n;i+=p)
#define all(a)  (a).begin(),(a).end()
#define int64 long long
#define debug cerr << __FILE__ << ":" << __LINE__ << endl;
#define INF 2147483647

struct Init {
    Init() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout.precision(20);
        cout << fixed;
    }
} init;

template <typename _Ty>
ostream& operator << (ostream& ostr, const vector<_Ty>& v) {
    for(int i = 0; i < (int) v.size(); i++) {
        ostr << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return ostr;
}

template <typename _K, typename _V>
ostream& operator << (ostream& ostr, const map<_K, _V>& v) {
    ostr << "{";
    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        ostr << (*iter).first << ": " << (*iter).second << ", ";
    }
    ostr << "}";
    return ostr;
}

template <typename _K>
ostream& operator << (ostream& ostr, const set<_K>& v) {
    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        ostr << *iter << (iter != v.end() ? " " : "");
    }
    return ostr;
}

template <typename _K, typename _V>
ostream& operator << (ostream& ostr, const pair<_K, _V>& v) {
    ostr << v.first << " " << v.second;
    return ostr;
}

int64 powmod(int64 n, int64 count, int64 mod) {
    if (count == 0) return 1;
    if (count % 2 == 0) {
        int64 t = powmod(n, count / 2, mod);
        return t * t % mod;
    }
    return n * powmod(n, count - 1, mod) % mod;
}

int64 ncr(int64 n, int64 r, int64 mod) {
    int64 a;
    if (n < r) a = min(n, r - n);
    else a = min(n - r, r);

    int64 res = 1;
    rep(i, a) {
        res = res * (n - i) % mod;
        res = res * powmod(i + 1, mod - 2, mod) % mod;
    }

    return res;
}

int main() {
    string s; cin >> s;
    cout << ((s == "AAA" || s == "BBB") ? "No" : "Yes") << endl;
}
