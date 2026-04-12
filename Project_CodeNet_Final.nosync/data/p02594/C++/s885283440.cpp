// Template //
#include<bits/stdc++.h>
using namespace std;

// マクロ //
#define rep(v,times) for(int v = 0; v < (int)(times); v++)
#define req(v,first,endplus1) for(int v = first; v < (int)(endplus1); v++)
#define all(x) x.begin(), x.end()
#define sort(x) sort(all(x))
#define uniq(x) x.erase(unique(all(x)), x.end())
#define vsum(x) accumulate(all(x), 0)
#define cou(x) cout << x << endl
#define y() cout << "Yes" << endl
#define n() cout << "No" << endl
#define Y() cout << "YES" << endl
#define N() cout << "NO" << endl
#define x2(x) (x) * (x)

// 型エイリアス //
using lint = long long;
using pii = pair<int, int>;
using vpii = vector<pii>;
using plili = pair<lint, lint>;
using vplili = vector<plili>;
using vi = vector<int>;
using vli = vector<lint>;
using vc = vector<char>;
using vs = vector<string>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vvli = vector<vli>;
using vvb = vector<vb>;
using vvc = vector<vc>;
using vvs = vector<vs>;
using mii = map<int, int>;
using mili = map<int, lint>;
using mci = map<char, int>;
using mcli = map<char, lint>;
using msi = map<string, int>;
using msli = map<string, lint>;


// 関数 //
template<class T, class Q> lint gcd_(T a, Q b) {
    int t;
    while (b != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

template<class T, class Q> lint lcm_(T a, Q b) {
    return a * b / gcd_(a, b);
}

template<class T, class Q> double distance(T a, Q b) {
    double dist;
    dist = sqrt(x2(a.first - b.first) + x2(a.second - b.second));
    return dist;
}

lint perm(int a) {
    lint perm = 1;
    for (int i = a; i >= 1; i--) {
        perm *= i;
    }
    return perm;
}

lint combination(int n, int m) {
    long double c = 1;
    for (int i = n, k = 1; i > m; i--, k++) {
        c *= i;
        c /= k;
    }
    return (lint)c;
}

template<class T, class Q> inline bool chmin(T& a, Q b) {
    if (a > b) { 
        a = b;
        return true; 
    }
    return false;
}

template<class T, class Q> inline bool chmax(T& a, Q b) {
    if (a < b) { 
        a = b; 
        return true; 
    }
    return false;
}

// 定数 //
const double pi = acos(-1);
const int mod = 1000000007;
const int inf = 1045141919;
const lint linf = ((1LL << 62) - 1);
const int dx4[4] = { 1,0,-1,0 };
const int dy4[4] = { 0,1,0,-1 };
const int dx8[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy8[8] = { 0,1,1,1,0,-1,-1,-1 };

// End of Template //



int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
        
    int N;
    cin >> N;

    N >= 30 ? y() : n();


}