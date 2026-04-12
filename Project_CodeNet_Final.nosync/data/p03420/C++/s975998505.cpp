#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;

    if(!k)
        return cout << n * n << '\n', 0;

    long long b = n - k;

    long long answer = 0;

    for(int i = n; i > k; --i)
    {
        long long h = n / i;

        answer += (i - k) * h;

        long long val = n - h * i;
        answer += max(0ll, val + 1 - k);
    }

    cout << answer << '\n';
}
