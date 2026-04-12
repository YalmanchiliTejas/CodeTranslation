
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
using VS = vector<string>;
using VVI = vector<VI>;
using VVL = vector<VL>;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, s, n, d) for (int i = (s); i < (int)(n); i += (d))
#define allpt(v) (v).begin(), (v).end()
#define allpt_c(v) (v).cbegin(), (v).cend()
#define allpt_r(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7, mod2 = 998244353, mod3 = 1e9 + 9;
const ll inf = 1e18;

const string wsp = " ";
const string tb = "\t";
const string rt = "\n";

template <typename T>
void show1dvec(const vector<T> &v)
{
    if (v.size() == 0)
        return;
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << wsp;
    cout << v[n] << rt;

    return;
}

template <typename T>
void show2dvec(const vector<vector<T>> &v)
{
    int n = v.size();
    rep(i, n) show1dvec(v[i]);
}

template <typename T, typename S>
void show1dpair(const vector<pair<T, S>> &v)
{
    int n = v.size();
    rep(i, n) cout << v[i].first << wsp << v[i].second << rt;
    return;
}

template <typename T, typename S>
void pairzip(const vector<pair<T, S>> &v, vector<T> &t, vector<T> &s)
{
    int n = v.size();
    rep(i, n)
    {
        t.push_back(v[i].first);
        s.push_back(v[i].second);
    }
    return;
}

template <typename T>
void maxvec(vector<T> &v)
{
    T s = v[0];
    int n = v.size();
    rep(i, n - 1)
    {
        if (s > v[i + 1])
        {
            v[i + 1] = s;
        }
        s = v[i + 1];
    }
}

template <typename T, typename S>
bool myfind(T t, S s)
{
    return find(t.cbegin(), t.cend(), s) != t.cend();
}

bool check(int y, int x, int h, int w)
{
    return 0 <= y && y < h && 0 <= x && x < w;
}

template <typename T>
vector<T> cumsum(const vector<T> &v)
{
    T s = 0;
    vector<T> ret = {0};

    rep(i, v.size())
    {
        s += v[i];
        ret.push_back(s);
    }
    return ret;
}

bool iskadomatsu(int a, int b, int c)
{
    return (a != b && b != c && c != a) && ((a > b && b < c) || (a < b && b > c));
}

VS split(string s, char c)
{
    VS ret;
    string part;
    s += c;
    rep(i, s.length())
    {
        if (s[i] == c)
        {
            ret.emplace_back(part);
            part = "";
        }
        else if (s[i] != c)
        {
            part += s[i];
        }
    }
    return ret;
}

string removezero(string &s)
{
    string ret;
    for (auto z : s)
        if (z != '0')
            ret += z;
    return ret;
}

ll sumdigit(ll x)
{
    ll ans{0};
    while (x > 0)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}



int main()
{

    cin.tie(0);
    ios::sync_with_stdio(false);

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    const ll llmin = -1e18; 
    int n;
    cin >> n;
    VL num(n);
    rep(i, n) cin >> num[i];
    if (n <= 3)
    {
        cout << *max_element(allpt_c(num)) << rt;
    }
    else if (n % 2 == 0)
    {
        VVL dp(2, VL(n, llmin));
        dp[0][0] = num[0];
        dp[1][1] = num[1];
        dp[0][2] = num[0] + num[2];
        rep2(i, 3, n)
        {
            dp[0][i] = max(dp[0][i - 2] + num[i], dp[0][i]);
            dp[1][i] = max(dp[1][i - 2] + num[i], dp[1][i]);
            dp[1][i] = max(dp[0][i - 3] + num[i], dp[1][i]);
        }
        cout << max(dp[0][n - 2], dp[1][n - 1]) << rt;
    }
    else
    {
        VVL dp(3, VL(n, llmin));
        ll ans{llmin};
        dp[0][0] = num[0];
        dp[1][1] = num[1];
        dp[0][2] = num[0] + num[2];
        dp[1][3] = max(num[1] + num[3], num[0] + num[3]);
        dp[2][2] = num[2];
        rep2(i, 4, n)
        {
            dp[0][i] = max(dp[0][i - 2] + num[i], dp[0][i]);
            dp[1][i] = max(dp[1][i - 2] + num[i], dp[1][i]);
            dp[1][i] = max(dp[0][i - 3] + num[i], dp[1][i]);
            dp[2][i] = max(dp[2][i - 2] + num[i], dp[2][i]);
            dp[2][i] = max(dp[1][i - 3] + num[i], dp[2][i]);
            dp[2][i] = max(dp[0][i - 4] + num[i], dp[2][i]);
        }

        ans = max(dp[0][n - 3], dp[1][n - 2]);
        ans = max(dp[2][n - 1], ans);
        cout << ans << rt;
    }
    
    
    return 0;
}
