#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

ll f(ll x, ll m)
{
    return x % m;
}

int main()
{
    ll N, X, M;
    map<ll, ll> entry;
    vector<ll> partial_sum;
    partial_sum.push_back(0);
    cin >> N >> X >> M;
    ll A = X;
    ll sum, period, sum_period;
    int i_0, i_1;
    sum = 0;
    for (int i = 1; i <= N; ++i)
    {
        sum += A;
        partial_sum.push_back(sum);
        if (entry[A] != 0)
        {
            i_0 = entry[A];
            i_1 = i;
            period = i_1 - i_0;
            sum_period = partial_sum[i_1] - partial_sum[i_0];
            ll containing_period = (N - (i_0 - 1)) / period;
            ll remain = N - (i_0 - 1) - containing_period * period;
            sum = partial_sum[i_0 - 1] + sum_period * containing_period + (partial_sum[i_0 + remain - 1] - partial_sum[i_0 - 1]);
            cout << sum;
            return 0;
        }
        entry[A] = i;
        A = f(A * A, M);
    }
    cout << sum;
    return 0;
}