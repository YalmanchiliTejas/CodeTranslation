#include <bits/stdc++.h>
#include <bitset>
#include <algorithm>
#define int long long
using namespace std;
#define mod 1000000007
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
bool vis[2000005], vis1[2000005];
vector<int> vec[2000005], v1;
int child[2000005];
int divi[2000005];
vector<pair<int, int>> v2[1000005];
// int parent[2000005];
// //int div1[100005];
// int min_indx[200005];
// int count1 = 0;
// int height = 0;
// int max_indx[200005];
// int f[100005];
// int cost[100005];
// stack<int> stc;
// int ans[100005];
// int count2;
// int sum[100005];
// int max1 = 0;
// //int count1 = 0;
// int dis[100005] = {0};
int h[100005];
int p[100005];
int dp[100005][100];
bool f = 0;
int bad[100005], good[100005];
int p5[100005];
void dfs(int node)
{
    vis[node] = 1;
    // cout << node << good[node] << " " << bad[node] << " "
    //      << "\n"; // if (vec[node].size() == 1)
    // //     cout << good[node] << bad[node] << "\n";
    for (int i = 0; i < vec[node].size(); i++)
    {
        int t_good = 0, t_bad = 0;
        if (!vis[vec[node][i]])
            // {
            //     if (vec[vec[node][i]].size() == 1)
            //     {
            //         // if (h[vec[node][i]] > p[vec[node][i]])
            //         //     f = 1;
            //         // if (fabs(h[vec[node][i]]) > p[vec[node][i]])
            //         //     f = 1;
            //         // if ((h[vec[node][i]] + p[vec[node][i]]) % 2 == 0)
            //         // {
            //         //     bad[vec[node][i]] = (p[vec[node][i]] - h[vec[node][i]]) / 2;
            //         //     good[vec[node][i]] = (p[vec[node][i]] + h[vec[node][i]]) / 2;
            //         // }
            //         // else
            //         // {
            //         //     f = 1;
            //         // }
            //     }
            dfs(vec[node][i]);

        // good[node] += good[vec[node][i]];
        // bad[node] += bad[vec[node][i]];
        // p5[node] += p5[vec[node][i]];
        // }
    }
}

// void dfs1(int node)
// {
//     vis[node] = 1;
//     // cout << node << "\n";
//     for (int i = 0; i < vec[node].size(); i++)
//     {
//         if (!vis[vec[node][i]])
//         {
//             sum[vec[node][i]] += sum[node];
//             //  cout << sum[vec[node][i]] << " " << sum[node] << "\n";

//             dfs1(vec[node][i]);
//         }
//     }
// }
// int MAXN = 200005;
// int LOGMAXN = (int)log2(200005) + 1;
// int M[200005][60];
int ans[200005];

void fun(int a, int b, int c)
{
    //ll val = 1;

    while (a <= b)
    {
        ans[a] += c;
        int p = -a;
        a += (a & p);
    }
}
int find1(int a)
{
    int sum = 0;
    while (a != 0)
    {
        sum += ans[a];
        int p = -a;
        a -= (a & p);
    }
    return sum;
}
// void process2(int A[], int N)
// {
//     int i, j;

//     for (i = 0; i < N; i++)
//         M[i][0] = i;
//     for (j = 1; 1 << j <= N; j++)
//         for (i = 0; i + (1 << j) - 1 < N; i++)
//             if (find1(M[i][j - 1]) < find1(M[i + (1 << (j - 1))][j - 1]))
//                 M[i][j] = M[i][j - 1];
//             else
//                 M[i][j] = M[i + (1 << (j - 1))][j - 1];
// }
int fastexpo(int a, int b, int m)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % m;
        b = b / 2;
        a = (a * a) % m;
    }
    return ans % m;
}

// int arr[100005] = {0}, arr2[1000005];
//int div1[20000005];
// int maxSubArraySum(int a[], int size)
// {
//     int max_so_far = -100000000000000000, max_ending_here = 0;
//     //    cout << max_so_far << " ";
//     int max_ind = 0, min_ind = 0, s = 0;
//     for (int i = 0; i < size; i++)
//     {
//         max_ending_here = max_ending_here + a[i];
//         // max_ind = i, min_ind = i;
//         if (max_so_far < max_ending_here)
//         {
//             max_so_far = max_ending_here;
//             max_ind = i;
//             min_ind = s;
//         }

//         if (max_ending_here < 0)
//         {
//             max_ending_here = 0;
//             s = i + 1;
//         }
//     }
//     // cout << max_so_far << "\n";
//     //  pair<int, int> p = {min_ind, max_ind};
//     return max_so_far;
// }
// bool ch(string s1, string s2)
// {
//     for (int i = 0; i < 7; i++)
//     {
//         if (s1[i] != s2[i])
//             return 0;
//     }
//     return 1;
// }
// int arr[100005][1010] = {0};
// void dijkstra(ll s, vector<pair<ll, ll>> vec2[], ll dis5[])
// {
//     priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
//     pq.push(make_pair(0, s));
//     dis5[s] = 0;
//     while (!pq.empty())
//     {
//         ll u = pq.top().second;
//         //  vis[u] = 1;
//         pq.pop();
//         for (ll i = 0; i < (ll)vec2[u].size(); i++)
//         {

//             ll q = vec2[u][i].second;
//             ll w = vec2[u][i].first;

//             if (dis5[u] + w < dis5[q])
//             {
//                 dis5[q] = dis5[u] + w;
//                 pq.push(make_pair(dis5[q], q));
//             }
//         }
//     }
// }
class MyClass
{
    int a;
    void co()
    {
        cout << a << "\n";
    }
};
// vector<int> prime;
// void run()
// {
//     int j = 1;
//     for (int i = 2; i < 1000001; i++)
//     {
//         if (!vis1[i])
//             while (i * j < 1000001)
//             {
//                 vis1[i * j] = 1;
//                 divi[i * j] = i;
//                 j++;
//             }
//         j = 1;
//     }
//     for (int i = 2; i < 1000001; i++)
//     {
//         // cout << i << " " << divi[i] << "\n";
//         if (i == divi[i])
//             prime.push_back(i);
//     }
//     for (int i = 1; i < 1000001; i++)
//     {
//         map<int, int> mp;
//         int p = i;
//         while (p > 1)
//         {
//             mp[divi[p]]++;
//             p /= divi[p];
//         }
//         for (auto itr : mp)
//         {
//             v2[i].push_back({itr.first, itr.second});
//         }
//     }
// }
//int arr[4000003];
int32_t main()
{
    int n;
    cin >> n;
    if (n >= 30)
    {
        cout << "Yes"
             << "\n";
    }
    else
    {
        cout << "No"
             << "\n";
    }

    return 0;
}