#include <bits/stdc++.h>

#define task "A"
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define Rep(i, r, l) for (int i = (r); i >= (l); --i)
#define DB(X) { cerr << #X << " = " << (X) << '\n'; }
#define DB1(A, _) { cerr << #A << "[" << _ << "] = " << (A[_]) << '\n'; }
#define DB2(A, _, __) { cerr << #A << "[" << _ << "][" << __ << "] = " << (A[_][__]) << '\n'; }
#define DB3(A, _, __, ___) { cerr << #A << "[" << _ << "][" << __ << "][" << ___ << "] = " << (A[_][__][___]) << '\n'; }
#define PR(A, l, r) { cerr << '\n'; rep(_, l, r) DB1(A, _); cerr << '\n';}
#define SZ(x) ((int)(x).size())
#define pb push_back
#define pf push_front
#define F first
#define S second
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } // sort(arr, arr + N, by(a));
#define next nextalscjaowjico
#define prev prevoua0wucckjsl
#define y1 y1kscj9u20cjeijc
#define left leftljascjljl
#define right rightsocjolkjl
#define y0 y0cqu3jioajc

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;

int main()
{
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
#else
    //freopen(task".in","r",stdin);
    //freopen(task".out","w",stdout);
#endif
    string s;
    cin >> s;
    bool a = 0, b = 0;
    rep(i, 0, 2) if (s[i] == 'A') a = 1;
    else b = 1;
    if (a && b) cout << "Yes";
    else cout << "No";
    return 0;
}
