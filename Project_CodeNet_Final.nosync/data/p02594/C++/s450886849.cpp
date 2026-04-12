#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
void fst()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}
int mod = 1e9 + 7;
int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a;
            res %= mod;
        }
        a = a * a;
        a %= mod;
        b >>= 1;
        b %= mod;
    }
    return res;
}
#define Darr(x)           \
    cerr << #x << " = ";  \
    for (auto i : x)      \
        cerr << i << " "; \
    cerr << "\n";

#define all(a) a.begin(), a.end()
#define pb push_back
#define deb(x) cerr << #x << "=" << x << " ";
//#define int long long
#define R(n) for (int i = 0; i < n; i++)
#define Rj(n) for (int j = 0; j < n; j++)
#define F(i, a, n) for (int i = a; i <= n; i++)
#define MN(x, y) x = min(x, y);
#define MX(x, y) x = max(x, y);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

int32_t main()
{
    int n;
    cin>>n;
    if(n>=30)return cout<<"Yes",0;
    cout<<"No";


}
