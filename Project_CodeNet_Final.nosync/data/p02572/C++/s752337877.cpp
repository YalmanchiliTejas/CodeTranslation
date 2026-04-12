#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define INF 1e9

using namespace std;

int N;

int main(void)
{
    cin >> N;
    // vector<unsigned long long> A;
    vector<unsigned long long> A(N, 0ULL);
    rep(i, N)
    {
        cin >> A[i];
        // A.push_back(1000000000ULL);
    }

    unsigned long long sum = 0ULL;
    unsigned long long max = accumulate(A.begin(), A.end(), 0ULL);
    unsigned long long mod = (unsigned long long)pow(10, 9) + 7ULL;

    for (int i = 0; i < N - 1; i++)
    {
        max -= A[i];
        sum += (A[i] % mod) * (max % mod);
        sum %= mod;
    }

    cout << sum << endl;
}