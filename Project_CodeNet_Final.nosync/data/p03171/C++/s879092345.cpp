#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long
int n;
int dp[3001][3001][2];
vector<int> data;
// int check( int start, int last, int  counter)
// {


//     int mul;
//     mul = (counter ? 1 : -1);
//     if (dp[start][last][counter] != -1) return dp[start][last][counter];
//     if (start == last) return data[start] * mul;

//     int v1 = data[start] * mul  + check(start + 1, last, !counter);
//     int v2 = data[last] * mul  + check(start, last - 1, !counter);
//     cout << v1 << " " << v2 << "\n";
//     return counter ? (dp[start][last][counter] = (max(v1, v2) % mod)) : ( dp[start][last][counter] = (min(v1, v2) % mod));


// }
int change(int k)
{
    if (k)return 0;
    return 1;
}
int check(int i, int j, int k)
{
    if (i == j)return (k == 1) ? -data[j] : data[j];
    if (dp[i][j][k] != -1)return dp[i][j][k];
    int value = 1;
    if (k == 1)value *= -1;
    int x = data[i] * value + check(i + 1, j, change(k));
    int y = data[j] * value + check(i, j - 1, change(k));
    if (k)
        return dp[i][j][k] = min(x, y);
    return dp[i][j][k] = max(x, y);
}
void findAns()
{


    cin >> n;
    data.resize(n);
    for (int i = 0; i < n; i++) cin >> data[i];

    int counter  = 0;
    memset(dp, -1, sizeof(dp));
    cout << check(0, n - 1, counter);


    // cout << value;
    return;




}
int32_t main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    FAST;

    // ll int t;
    // cin >> t;
    // while (t--)
    findAns();

    return 0;
}