#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define X first
#define Y second
#define pb push_back
#define make_unique(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
#define int long long

const LL mod = 1e9 + 7;


template<class T>
istream& operator >> (istream& in, vector<T>& v){ for (auto &x : v) { in >> x; } return in; }

template<class T, class U>
istream& operator >> (istream& in, pair<T, U> & v){ in >> v.X >> v.Y;return in; }

template<class T, class U>
ostream& operator << (ostream& out, pair<T, U> & v){ out << v.X << " " << v.Y;return out; }

void chkmax(int &a, int b) {
    a = max(a, b);
    return;
}

void chkmin(int &a, int b) {
    a = min(a, b);
    return;
}

LL ppow (LL x, LL s) {
    if (!s) return 1;
    if (!(s - 1)) return x % mod;
    if (s % 2) return (x * ppow (x, s - 1)) % mod;
    LL b = ppow (x, s / 2);
    return (b * b) % mod;
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("ILUXA.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    cout << ((n == m) ? "Yes" : "No");
    return 0;
}
