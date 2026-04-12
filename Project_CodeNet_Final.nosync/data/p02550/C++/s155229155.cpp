#include <bits/stdc++.h>
#include <bitset>
#include <algorithm>
#define mod (int)998244353
#define int long long
using namespace std;
#define INF (int)pow(2, 32) - 1
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int vis[15000005], vis1[5000005];
vector<int> vec[3000005];
// map<int, int> v2[5000005];
// v1, vec1[3000005];
//int child[2000005];
//int divi[2000005];
// int dp[100001];
// // int dis[100005] = {0};
// // int h[100005];
// // int p[100005];
// // int dp[100005][100];
// // bool f = 0;
// // int bad[100005], good[100005];
// // int p5[100005];
// // int final_sum[300005], max_sum[10005];
// // //int level[200005];
// // //int time1 = 0;
// int parent1[100001];
// void dfs(int node, int parent)
// {
//     vis[node] = 1;
//     parent1[node] = parent;
//     //level[node] = time1;
//     //  time1++;
//     for (int i = 0; i < vec[node].size(); i++)
//     {
//         if (!vis[vec[node][i]])
//         {
//             //  if (bit[vec[node][i]]            {

//             dfs(vec[node][i], node);
//             dp[node] += dp[vec[node][i]];
//             //  final_sum[node] += final_sum[vec[node][i]];
//         }
//     } //  if ()
//       //   if (b == 0)
//       //  count1[b][node] += count1[b][vec[node][i]];
//       //}
//       // time1--;
// }
// // int divi[5000005];
// // int dp[5000007];
// // int pre_sum[5000005];
// // vector<int> prime;
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
int fastexpo(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        b = b / 2;
        a = (a * a) % mod;
    }
    return ans % mod;
}
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
// int dp[1000001];
// int ans[1000001];
int tenary_search(vector<int> v)
{
    int l = 0, r = v.size() - 1;
    while (r > l)
    {

        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        //  cout << mid1 << " " << mid2 << "\n";
        int ans1 = abs(v[mid1] - v[0]) + abs(v.back() - v[mid1 + 1]);
        int ans2 = abs(v[mid2] - v[0]) + abs(v.back() - v[mid2 + 1]);
        int ans3 = abs(v[mid1 - 1] - v[0]) + abs(v.back() - v[mid1]);
        int ans4 = abs(v[mid2 - 1] - v[0]) + abs(v.back() - v[mid2]);
        ans1 = min(ans1, ans3);
        ans2 = min(ans2, ans4);
        if (ans1 > ans2)
        {
            l = mid1 + 1;
        }
        else
        {
            if (ans1 == ans2)
            {
                l = mid1;
                r = mid2 - 1;
            }
            else
                r = mid2 - 1;
        }
        // cout << l << " " << r << "\n";
    }
    return l;
}
int fun(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int fun1(int length1, int length2, int dis)
{
    int p = length1;
    length1 += (2 * length2);
    //o cout << length1 << "\n";
    length1 *= 4;
    //  cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    //  int dis = fun(x1, y1, x2, y2);
    cout << "cskb" << length1 << "\n";
    dis -= length1;
    cout << dis << "\n";
    if (dis <= 0)
    {
        return 1;
    }
    dis *= dis;
    length2 *= (p * 128);
    //  cout << length2 << " " << dis << "\n";
    if (length2 >= dis)
    {

        return 1;
    }
    else
    {

        return 0;
    }
}
int fun2(int length1, int length2, int dis)
{
    int p = length1;
    dis -= 32 * (length1 + length2);
    if (dis <= 0)
    {
        return 1;
    }
    dis *= dis;
    length2 *= (p * 128);
    //  cout << length2 << " " << dis << "\n";
    if (length2 >= dis)
    {

        return 1;
    }
    else
    {

        return 0;
    }
}
int dp[200005];
int32_t main()
{

    int n, x, m;
    cin >> n >> x >> m;
    bool vis[m] = {0};
    int ans = x;
    int i;
    int sum = x;
    vis[x] = 1;
    vector<int> vec;
    vec.push_back(x);
    int ind;
    bool f = 0;
    for (i = 0; i < m; i++)
    {
        int p = (ans * ans) % m;
        if (vis[p])
        {
            ind = p;
            break;
        }
        else
        {
            vis[p] = 1;
            sum += p;
            vec.push_back(p);
            ans = p;
            if ((i + 2) == n)
            {
                // cout << "scisd"
                //    << "\n";
                f = 1;
                break;
            }
        }

        // cout << sum << "\n";
    }
    if (f)
    {
        // cout << "efuye"
        //    << "\n";
        cout << sum << "\n";
        return 0;
    }
    // cout << ind << "\n";
    //  cout << vec.size() << " " << ind << "\n";
    // for (int l = 0; l < vec.size(); l++)
    //     cout << vec[l] << " ";
    int temp;
    int sum1 = 0;
    for (int j = 0; j < i + 1; j++)
    {

        if (vec[j] == ind)
        {

            f = 1;
            temp = j;
        }
        if (f)
        {
            sum1 += vec[j];
        }
    }
    //cout << temp << "\n";
    int k = vec.size() - temp;
    //  cout << k << "\n";
    n -= vec.size();
    // cout << n << "\n";
    int mod1 = (n % k);
    int div2 = (n / k);
    sum += (sum1 * div2);
    for (int l = temp; l < temp + mod1; l++)
    {
        sum += vec[l];
    }

    cout << sum << "\n";
    return 0;
}