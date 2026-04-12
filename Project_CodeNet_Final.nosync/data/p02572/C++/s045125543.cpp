#include<bits/stdc++.h>
using namespace std;
#define ll    long long
#define pb          push_back
#define F first
#define S second
#define    endl        '\n'
#define all(v) (v).begin(), (v).end()
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    string sep;
    for (const auto &x : v) os << sep << x, sep = ", ";
    return os << '}';
}
template<typename T, size_t size> ostream &operator<<(ostream &os, const array<T, size> &arr)
{
    os << '{';
    string sep;
    for (const auto &x : arr) os << sep << x, sep = ", ";
    return os << '}';
}
template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os   << '(' << p.first << ", " << p.second << ')';
}
void dbg_out()
{
    cerr << endl;
}
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}

#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
const int N = 1000 + 5;
void solve()
{
    ll n, m = 1e9 + 7, s = 0, ans = 0;
    cin >> n;
    std::vector<ll> v(n);
    for(ll &i : v) cin >> i, s += i;
    for(ll i : v)
    {
        s-=i;
        ans+=s%m*i%m;
        ans%=m;
    }
    cout<<ans;



}
int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    ll TESTS = 1;
    // cin >> TESTS;
    for(int t = 1; t <= TESTS; t++)
    {
        solve();
    }
    return 0;
}