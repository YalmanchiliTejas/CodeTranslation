#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    if(K == 0)
    {
        cout << N * N << endl;
        return 0;
    }
    ll answer = 0;
    for (int i = K + 1; i <= N; i++)
    {
        answer += (N / i) * (i - K);
        answer += max(0LL, (N % i) - K + 1);
    }
    cout << answer << endl;
    return 0;
}
