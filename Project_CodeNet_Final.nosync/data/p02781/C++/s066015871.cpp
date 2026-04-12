//#define _GLIBCXX_DEBUG
#include "bits/stdc++.h"

using namespace std;

//------------------------------- Type Names -------------------------------//

using i64 = int_fast64_t;

using seika = string;
//{akari : 1D, yukari : 2D, maki : 3D} vector
template <class kizuna>
using akari = vector<kizuna>;
template <class yuzuki>
using yukari = akari<akari<yuzuki>>;
template <class tsurumaki>
using maki = akari<yukari<tsurumaki>>;
//{akane : ascending order, aoi : decending order} priority queue
template <class kotonoha>
using akane = priority_queue<kotonoha, akari<kotonoha>, greater<kotonoha>>;
template <class kotonoha>
using aoi = priority_queue<kotonoha>;

//------------------------------- Libraries ---------------------------------//

//------------------------------- Dubug Functions ---------------------------//

inline void print()
{
    cout << endl;
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest)
{
    cout << first << ' ';
    print(rest...);
}

//------------------------------- Solver ------------------------------------//

void solve()
{
    seika n;
    int k;
    cin >> n >> k;
    yukari<i64> dp(2, akari<i64>(k + 1));
    dp[0][0] = 1;
    for (char c : n)
    {
        yukari<i64> new_dp(2, akari<i64>(k + 1));
        int x = c - '0';
        for (int f = 0; f < 2; f++)
            for (int d = 0; d < 10; d++)
                for (int j = 0; j <= k; j++)
                {
                    if (!f && x < d)
                    {
                        continue;
                    }
                    bool nf = f || x != d;
                    if ((!!d + j) > k)
                    {
                        continue;
                    }
                    new_dp[nf][!!d + j] += dp[f][j];
                }
        swap(dp, new_dp);
    }
    i64 ans = dp[0][k] + dp[1][k];
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
