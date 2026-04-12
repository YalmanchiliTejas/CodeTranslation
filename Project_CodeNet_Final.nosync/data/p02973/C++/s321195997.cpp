#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, end) for (int i = begin; i > end; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

int N;
int A[101010];
vector<int> b;

int main()
{
    cin >> N;
    rep(i, 0, N)
    {
        cin >> A[i];
    }

    b.push_back(A[N - 1]);
    repre(i, N - 2, 0)
    {
        if (b[b.size() - 1] <= A[i])
        {
            b.push_back(A[i]);
        }
        auto ub = upper_bound(b.begin(), b.end(), A[i]);
        *ub = A[i];
    }

    cout << b.size() << endl;
}
