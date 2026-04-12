#include "bits/stdc++.h"

using namespace std;

//------------------------------- Libraries --------------------------------//

//------------------------------- Type Names -------------------------------//

using i64 = int_fast64_t;

using seika = string;
//akari : 1D, yukari : 2D, maki : 3D vector
template <class kizuna>
using akari = vector<kizuna>;
template <class yuzuki>
using yukari = akari<akari<yuzuki>>;
template <class tsurumaki>
using maki = akari<yukari<tsurumaki>>;
//akane : ascending order, aoi : decending order
template <class kotonoha>
using akane = priority_queue<kotonoha, akari<kotonoha>, greater<kotonoha>>;
template <class kotonoha>
using aoi = priority_queue<kotonoha>;

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
    int n;
    cin >> n;
    akari<i64> as(n), bs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> as[i];
    }
    sort(as.begin(), as.end());
    if (n & 1)
    {
        i64 ans = 0, ans2 = 0;
        int plus = (n + 1) / 2, minus = n - plus;
        ans += accumulate(as.begin() + minus + 2, as.end(), (i64)0) * 2;
        ans -= accumulate(as.begin(), as.begin() + minus, (i64)0) * 2;
        ans += as[minus + 1] + as[minus];
        swap(plus, minus);
        ans2 += accumulate(as.begin() + minus, as.end(), (i64)0) * 2;
        ans2 -= accumulate(as.begin(), as.begin() + minus - 2, (i64)0) * 2;
        ans2 -= as[minus - 2] + as[minus - 1];
        ans = max(ans, ans2);
        cout << ans << endl;
    }
    else
    {
        i64 ans = 0;
        ans += accumulate(as.begin() + n / 2 + 1, as.end(), (i64)0) * 2;
        ans -= accumulate(as.begin(), as.begin() + n / 2 - 1, (i64)0) * 2;
        ans += as[n / 2] - as[n / 2 - 1];
        cout << ans << endl;
    }
}

int main()
{
    solve();
    return 0;
}
