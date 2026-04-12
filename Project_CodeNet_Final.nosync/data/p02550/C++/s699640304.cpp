#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ff first
#define ss second
#define pb push_back
#define print(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int bexp(int a, int b, int mod)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = (res * a) % mod;

        a = (a * a) % mod; 
        b >>= 1;
    }
    return res;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

const int N = 100010;
const int mod = 998244353;

struct comp {
    bool operator() (const pair<int, int> a, const pair<int, int> b) const
    {
        return a.ss > b.ss;
    }
};

int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    
    int n, x, m;
    cin >> n >> x >> m;

    int p = x;
    int f[m] = {};
    vector<int> a;
    a.pb(0);

    while (n) {
        if (f[p] == 1) {
            break;
        }

       
        f[p]++;
        n--;
        a.pb(p + a.back());
        p = p * p % m;
    } 

    int ans = a.back();

    int in = 0;
    for (int i = 1; i < (int)a.size(); ++i)
    {
        if (a[i] - a[i - 1] == p) {
            in = i;
            break;
        }
    }

    // cout << ans << " " << n << " " << in <<  "\n";
    int no = a.size() - in;

    if (in != 0)
        ans = ans + n / no * (a.back() - a[in - 1]);

    if (in != 0)
        ans = ans + (a[in + n % no - 1] - a[in - 1]);

    cout << ans << endl;
    return 0;
}