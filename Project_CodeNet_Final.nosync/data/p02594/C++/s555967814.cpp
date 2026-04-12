/*
* Author : Omkar Deshmukh
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(v) v.begin(), v.end()
#define intvect vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define boolv vector<bool>
#define ld long double
#define deb(x) cout << #x << " " << x << endl;
#define pb push_back
#define pob pop_back
#define F first
#define S second
#define ub upper_bound
#define bs binary_search
#define lb lower_bound
#define ull unsigned long long

// bool flag = 0;
// const ll mod = 1e9 + 7;
// const ll N = (ll)5e5 + 4;
// bool ans = 0;
template <typename... T>
void read(T &... args)
{
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&... args) //rvalue references
{
    ((cout << args), ...);
}

void vjudge()
{
#ifndef ONLINE_JUDGE
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    int n;
    read(n);
    if (n >= 30)
        write("Yes");
    else
        write("No");
}

int32_t main()
{
    vjudge();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
