#include <bits/stdc++.h>
#include <bitset>
#include <algorithm>
#define mod (int)1000000007
#define int long long
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int vis[15000005], vis1[5000005];
vector<int> vec[3000005];
// map<int, int> v2[5000005];
// v1, vec1[3000005];
//int child[2000005];
//int divi[2000005];

// int dis[100005] = {0};
// int h[100005];
// int p[100005];
// int dp[100005][100];
// bool f = 0;
// int bad[100005], good[100005];
// int p5[100005];
// int final_sum[300005], max_sum[10005];
// //int level[200005];
// //int time1 = 0;
int dp[100002][505] = {0};
int a[100002];
int ans1 = 0;
void dfs(int node)
{
    vis[node] = 1;
    //level[node] = time1;
    //  time1++;
    for (int i = 0; i < vec[node].size(); i++)
    {
        if (!vis[vec[node][i]])
        {
            //  if (bit[vec[node][i]]            {

            dfs(vec[node][i]);
            for (int j = 0; j < 505; j++)
            {
                dp[node][j] += dp[vec[node][i]][j];
            }
            // dp[node][a[node]] += 1;
            //  final_sum[node] += final_sum[vec[node][i]];
        }
    }

    for (int j = 1; j <= 7; j++)
    {

        if (dp[node][j] > 0)
        {

            int a1 = a[node] * j;
            int p = sqrt(a1);
            p *= p;

            if (a1 == p)
            {

                ans1 += dp[node][j];
                // cout << "yes " << dp[node][j] << " ";
            }
        }
        //  ans1 -= 1;
    }

    dp[node][a[node]] += 1;
}
// int divi[5000005];
// int dp[5000007];
// int pre_sum[5000005];
// vector<int> prime;
// void run()
// {
//     int j = 1;
//     for (int i = 2; i < 5000001; i++)
//     {
//         if (!vis1[i])
//             while (i * j < 5000001)
//             {
//                 vis1[i * j] = 1;
//                 divi[i * j] = i;
//                 j++;
//             }
//         j = 1;
//     }
//     // cout
//     // cerr
//     //     << "sdksd"
//     //     << "\n";
//     // for (int i = 2; i < 5000001; i++)
//     // {
//     //     // cout << i << " " << divi[i] << "\n";
//     //     if (i == divi[i])
//     //         prime.push_back(i);
//     // }
//     for (int i = 1; i < 5000001; i++)
//     {
//         map<int, int> mp;
//         int p = i;
//         while (p > 1)
//         {
//             dp[i]++;
//             p /= divi[p];
//         }
//         //cout << mp.size() << "\n";
//         //v2[i] = v2[i - 1];
//         // for (auto itr : mp)
//         //  {
//         //    v2[i][itr.first] += itr.second;
//         //   }
//         // cerr << i << "hkcxhx"
//         //    << "\n";
//     }
//     for (int i = 1; i < 5000001; i++)
//     {
//         pre_sum[i] = pre_sum[i - 1] + dp[i];
//         // for( auto itr)
//     }
// }
// // int fastexpo(int a, int b)
// // {
// //     int ans = 1;
// //     while (b)
// //     {
// //         if (b & 1)
// //             ans = (ans * a) % mod;
// //         b = b / 2;
// //         a = (a * a) % mod;
// //     }
// //     return ans % mod;
// // }
// // int lowerIndex(int arr[], int n, int x)
// // {
// //     int l = 0, h = n - 1;
// //     while (l <= h)
// //     {
// //         int mid = (l + h) / 2;
// //         if (arr[mid] >= x)
// //             h = mid - 1;
// //         else
// //             l = mid + 1;
// //     }
// //     return l;
// // }

// // // function to find last index <= y
// // int upperIndex(int arr[], int n, int y)
// // {
// //     int l = 0, h = n - 1;
// //     while (l <= h)
// //     {
// //         int mid = (l + h) / 2;
// //         if (arr[mid] <= y)
// //             l = mid + 1;
// //         else
// //             h = mid - 1;
// //     }
// //     return h;
// // }

// // // function to count elements within given range
// //int countInRange(int arr[], int n, int x, int y)
// // {
// //     // initialize result
// //     int count = 0;
//     count = upperIndex(arr, n, y) - lowerIndex(arr, n, x) + 1;
//     return count;
// }

int32_t main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int suff[n];
    suff[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suff[i] = (suff[i + 1] + arr[i]) % mod;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans = (ans + arr[i] * suff[i + 1]) % mod;
    }
    cout << ans << "\n";

    return 0;
}