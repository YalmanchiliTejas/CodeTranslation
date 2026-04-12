#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define INF 1LL << 60;
#define LLINF 1e12
#define PI 3.14159265359
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int ny, nx;
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll lcm(ll m, ll n)
{
    if ((0 == m) || (0 == n))
        return 0;
    return ((m / gcd(m, n)) * n);
}

ll llpow(ll x, ll y)
{
    ll ans = 1;
    REP(i, y)
    ans *= x;
    return ans;
}

ll llmin(ll x, ll y) { return x < y ? x : y; }
ll llmax(ll x, ll y) { return x > y ? x : y; }

template <typename Container>
bool exist_in(const Container &c, const typename Container::value_type &v)
{
    return (c.end() != std::find(c.begin(), c.end(), v));
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

ll nCr(int n, int r)
{
    if (n == r or n == 0)
        return 1;
    if (n < r)
        return 0;
    if (r == 1)
        return n;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

//std::cout << std::defaultfloat << std::setprecision(10);
////////////////////////////////////////
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    vector<string> S(n);
    int res[n][27]={0};
    
    REP(i,n){
        cin >> S[i];
        REP(j,S[i].size()){
            res[i][S[i][j]-'a']++;
        }
    }

    string ans;

    REP(i,27){
        int cnt=0, hold=100000;
        REP(j,n){
            if(res[j][i]!=0){
                cnt = res[j][i];
                if(cnt<hold) hold=cnt;
            }else{
                hold = 0;
                goto label;
            }
        }
        label: int hoge=0;
        REP(j,hold) ans.push_back(i+'a');
    }

    cout << ans << endl;

    return 0;
}
