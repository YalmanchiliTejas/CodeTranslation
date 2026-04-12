#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define fr                first
#define sc                second
#define vc                vector
#define endl              '\n'
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define LSB(i)            ((i)&-(i))

template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 3000 + 5;
int dp[2][N][N];
int a[N];
int n;
int x = 0, y = 0;

int dynamic(int turn, int left, int right, int moves)
{
    if (moves >= n)
        return 0;
    if (dp[turn][left][right] != -1)
        return dp[turn][left][right];
    int ans = 0;
    if (turn == 0)
    {
        ans += max(dynamic(1, left + 1, right, moves + 1) + a[left], dynamic(1, left, right - 1, moves + 1) + a[right]);
    }
    if (turn == 1)
    {
        ans += min(dynamic(0, left + 1, right, moves + 1) - a[left], dynamic(0, left, right - 1, moves + 1) - a[right]);
    }
    //int ans = x - y;
    dp[turn][left][right] = ans;
    return ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mem1(dp);
    cout << dynamic(0, 0, n - 1, 0);
}
signed main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    //cin>>t;
    while (t--) solve();
    return 0;
}