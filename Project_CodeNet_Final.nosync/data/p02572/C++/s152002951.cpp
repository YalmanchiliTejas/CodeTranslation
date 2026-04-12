#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <cstdio>
#include <numeric>
#include <iomanip>

using namespace std;

using ll = long long;

const ll mod = 1e9 + 7;

ll N;
vector<ll> A;

int main()
{
    cin >> N;
    A.resize(N + 5);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    ll ans = 0;
    ll sum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        sum = (sum + A[i]) % mod;
        ans += ((sum * A[i + 1]) % mod);
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
}