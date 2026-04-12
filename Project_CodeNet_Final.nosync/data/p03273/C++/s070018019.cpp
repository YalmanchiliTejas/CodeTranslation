//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
//-std=gnu++17
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
vector<string> s, ans;
int h, w;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    rep(i, h)
    {
        string temp;
        cin >> temp;
        bool c = false;
        rep(j, w)
        {
            if (temp[j] == '#')
            {
                c = true;
            }
        }
        if (c)
        {
            s.push_back(temp);
        }
    }
    map<int,bool>m;
    rep(j, w)
    {
        bool c=false;
        rep(i, s.size())
        {
            if (s[i][j] == '#')
            {
                c = true;
            }
        }
        if(c)
        m[j]=true;
    }
    rep(i,s.size()){
        rep(j,w){
            if(m[j]){
                cout<<s[i][j];
            }
        }
        cout<<"\n";
    }
}
