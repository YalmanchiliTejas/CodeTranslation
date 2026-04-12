#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
#define vcin(a)                          \
    for (int i = 0; i < (a).size(); i++) \
        cin >> (a)[i];

int main()
{
    int N;
    cin >> N;
    vint A(N), B(N), C(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    sort(all(A));
    int idx1 = 1, idx2 = N - 1;
    rep(i, N)
    {
        if (i == 0)
        {
            B[N / 2] = A[0];
        }
        else if (i % 4 == 1 or i % 4 == 2)
        {
            if (i % 2 == 1)
            {
                B[N / 2 - (i / 2 + 1)] = A[idx2--];
            }
            else
            {
                B[N / 2 + (i / 2)] = A[idx2--];
            }
        }
        else
        {
            if (i % 2 == 1)
            {
                B[N / 2 - (i / 2 + 1)] = A[idx1++];
            }
            else
            {
                B[N / 2 + (i / 2)] = A[idx1++];
            }
        }
    }
    idx1 = 0;
    idx2 = N - 2;
    rep(i, N)
    {
        if (i == 0)
        {
            C[N / 2] = A[N - 1];
        }
        else if (i % 4 == 1 or i % 4 == 2)
        {
            if (i % 2 == 1)
            {
                C[N / 2 - (i / 2 + 1)] = A[idx1++];
            }
            else
            {
                C[N / 2 + (i / 2)] = A[idx1++];
            }
        }
        else
        {
            if (i % 2 == 1)
            {
                C[N / 2 - (i / 2 + 1)] = A[idx2--];
            }
            else
            {
                C[N / 2 + (i / 2)] = A[idx2--];
            }
        }
    }
    ll sum1 = 0, sum2 = 0;
    rep(i, N - 1)
    {
        sum1 += abs(B[i + 1] - B[i]);
        sum2 += abs(C[i + 1] - C[i]);
    }
    cout << max(sum1, sum2);
    return 0;
}