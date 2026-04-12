#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int N; cin >> N;
    vector<LLONG> As(N); for (auto &Ai : As) cin >> Ai;
    sort(As.begin(), As.end());
    if (N % 2 == 1) // N = 2m + 1 のとき
    {
        int m = (N - 1) / 2;
        // p1>=p2<=p3>=... となる場合，大きい方から(m+1)個を奇数番に置き，
        // 小さい方からm個を偶数番に置けばよい
        LLONG ans1 = 0;
        for (int i = 0; i < m - 1; ++i)
        {
            ans1 += As[N - 1 - i] * 2;
        }
        ans1 += As[N - m - 1] + As[N - m];  // 両端は１度ずつ
        for (int i = 0; i < m; ++i)
        {
            ans1 -= As[i] * 2;
        }
        // p1<=p2>=p3>=... となる場合，大きい方からm個を奇数番に置き，
        // 小さい方から(m+1)個を偶数番に置けばよい
        LLONG ans2 = 0;
        for (int i = 0; i < m; ++i)
        {
            ans2 += As[N - 1 - i] * 2;
        }
        for (int i = 0; i < m - 1; ++i)
        {
            ans2 -= As[i] * 2;
        }
        ans2 -= As[m - 1] + As[m];  // 両端は１度ずつ
        cout << max(ans1, ans2) << endl;
    }
    else // N = 2m のとき
    {
        int m = N / 2;
        // p1>=p2<=p3>=... となる場合，大きい方からm個を奇数番に置き，
        // 小さい方からm個を偶数番に置けばよい
        LLONG ans1 = 0;
        for (int i = 0; i < m - 1; ++i)
        {
            ans1 += As[N - 1 - i] * 2;
        }
        ans1 += As[N - m];  // 先頭は１度だけ
        for (int i = 0; i < m - 1; ++i)
        {
            ans1 -= As[i] * 2;
        }
        ans1 -= As[m - 1];  // 最後尾は１度だけ
        // p1<=p2>=p3>=... となる場合，大きい方からm個を奇数番に置き，
        // 小さい方からm個を偶数番に置けばよい
        LLONG ans2 = 0;
        for (int i = 0; i < m - 1; ++i)
        {
            ans2 += As[N - 1 - i] * 2;
        }
        ans2 += As[N - m];  // 最後尾は１度だけ
        for (int i = 0; i < m - 1; ++i)
        {
            ans2 -= As[i] * 2;
        }
        ans2 -= As[m - 1];  // 先頭は１度だけ
        cout << max(ans1, ans2) << endl;
    }
}
