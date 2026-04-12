#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef uint64_t u64;
typedef int64_t s64;
typedef uint32_t u32;
typedef int32_t s32;
typedef vector<s32> vs32;
typedef vector<u32> vu32;
typedef vector<s64> vs64;
typedef vector<u64> vu64;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

#define CEIL(x, y) (((x) + (y) - 1) / (y))
#define MOD 1000000007ULL

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    rep (i, N)
    {
        cin >> A[i];
    }

    vs32 v;
    rep (i, N)
    {
        auto it = upper_bound(v.begin(), v.end(), A[i], [](const int x, const int y) { return x > y; });
        if (it == v.end())
        {
            v.push_back(A[i]);
        }
        else
        {
            *it = A[i];
        }
    }

    cout << v.size() << "\n";
    return 0;
}

