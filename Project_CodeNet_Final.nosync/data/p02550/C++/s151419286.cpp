//#include <tourist>
#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> p;
const int INF = 1e9;
const ll LINF = ll(1e18);
const int MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v)          \
    cout << #v << ":";    \
    for (auto x : v)      \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << endl;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
//cout<<fixed<<setprecision(15);有効数字15桁
//-std=c++14
//g++ yarudake.cpp -std=c++17 -I .
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, mod, x;
    cin >> n >> x >> mod;
    ll sum = x;
    ll y = x;
    map<ll, ll> m;
    vector<ll> sumv;
    m[x] = 1;
    sumv.push_back(0);
    sumv.push_back(x);
    if (n == 1)
        return cout << x << "\n", 0;
    for (int i = 1; i < n; i++)
    {
        ll z = (x * x) % mod;
        sum += z;
        x = z;
        //cout<<z<<"\n";
        sumv.push_back(sum);
        if (z == 0)
        {
            return cout << sum << "\n", 0;
        }
        //cout << z << "\n";
        //cout<<sum<<"\n";
        if (m[z] != 0)
        {
            ll temp = m[z];
            ll sumt = sumv[m[z]];
            ll va = sum - sumt;
            ll d = i - m[z]+1;
            ll ans = sum + (va * ((n - i-1) / d));
            //ans%=mod;
            ll temp2 = (n - i-1) % d;
            ans += sumv[m[z] + temp2]-sumv[m[z]];
            //cout << sumv[m[z] + temp2] - sumv[m[z]] << "\n";
            cout << ans << "\n";
            //cout << va << " " << d << " " << i << " " << (n - i-1) % d << " " << (n-i-1)/d<< "\n";
            return 0;
        }
        m[z] = i + 1;
    }
    cout << sum << "\n";
}