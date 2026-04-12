#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define int long long
#define fill(x, v) memset(x, v, sizeof(x))
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define ios std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
/*
std::cout << std::setprecision(9) << f << '\n';//3.141590000;
map<char,int>::reverse_iterator rit;
for(rit = mp.rbegin(); rit!=mp.rend(); rit++)
*/
int n;
int dp[3001][3001];
int arr[3001];
int x, y;
//dp[l][r]= max(a[l]-dp[l+1][r], a[r]-dp[l][r-]);
int winner()
{
    for (int l = n - 1; l >= 0; l--)
        for (int r = l; r < n; r++)
            if (l != r)
                dp[l][r] = max(arr[l] - dp[l + 1][r], arr[r] - dp[l][r - 1]);
            else
                dp[l][r] = arr[l];
    return dp[0][n - 1];
}
int32_t main()
{
    ios;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    x = winner();
    cout << x << endl;
}
