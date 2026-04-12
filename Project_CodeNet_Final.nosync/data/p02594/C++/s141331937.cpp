#pragma region RegionDefs
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define reps(i,l,r) for(int i=(l),i##_len=(r);i<i##_len;++i)
#define repr(i,l,r) for(int i=(r)-1,i##_left=(l);i>=i##_left;--i)
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
const ll INF = 1e9;
template<class T=ll> using V = vector<T>;
template<class T=ll> using PQ = priority_queue<T>;
template<class T=ll> using PQG = priority_queue<T, V<T>, greater<T>>;
const ll MOD = 1000000007LL;
void in() {}
template<class Head, class... Tail>
void in(Head&& head, Tail&&... tail) { cin >> head; in(move(tail)...); }
#define IN(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define INS(T, ...) T __VA_ARGS__; in(__VA_ARGS__)
#define VIN(T, v, n) V<T> v(n); for(auto& _elem:v)cin>>_elem
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if (a>b) {a=b; return 1;} return 0;}
template<class T>
string join(vector<T>& v, string delim="") { ostringstream os; rep(i,v.size())i?os<<delim<<v[i]:os<<v[0]; return os.str(); }
#pragma endregion RegionDefs

void solve()
{
    IN(x);
    if (x >= 30) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(numeric_limits<double>::max_digits10);

    solve();

    return 0;
}