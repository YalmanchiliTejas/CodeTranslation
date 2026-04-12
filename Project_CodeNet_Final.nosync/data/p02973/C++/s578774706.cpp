#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <map>
#include <utility>

using namespace std;

#define ll long long

void solve()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }

    vector<ll> sa;
    sa.push_back(A.at(N - 1));
    for (ll i = N - 2; i >= 0; i--)
    {
        auto iterL = upper_bound(sa.begin(), sa.end(), A.at(i));
        if (iterL == sa.end())
        {
            // 見つからなかったので色を追加
            sa.push_back(A.at(i));
        }
        else
        {
            // 見つかったので入れ替え
            *iterL = A.at(i);
        }
    }

    cout << sa.size() << endl;

    return;
}

int main()
{
    solve();
    return 0;
}
