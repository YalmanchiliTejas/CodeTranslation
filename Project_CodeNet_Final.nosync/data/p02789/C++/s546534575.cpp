#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rep(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define rrep(i, k, n) for (int i = (int)(n) - 1; i >= (int)(k); --i)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vv_ii;
typedef pair<int,ii> i_ii;
typedef vector<i_ii> vi_ii;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;

template <class T>
inline ostream& operator<<(ostream & o, vector<T> const& v) {
    for (int i = 0; i < (int)(v.size()) - 1; ++i)
        o << v[i] << ' ';
    if (!v.empty())
        o << v.back();
    return o;
}

template <class T, class Q>
inline ostream& operator<<(ostream & o, pair<T,Q> const& p) {
    o << "(" << p.fi << "," << p.se << ")";
    return o;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    
    int n, m;
    cin >> n >> m;
    cout << (n == m ? "Yes" : "No") << '\n';


    return 0;
}