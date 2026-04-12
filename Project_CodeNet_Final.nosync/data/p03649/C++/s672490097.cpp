#include <bits/stdc++.h>
#define prev someone_else_0
#define last someone_else_1
#define next someone_else_2

using namespace std;

const long double eps = 1e-9;

const int MaxN = 50 + 15;

long long a[MaxN];
long long A[MaxN];

int n;


bool trueCan(long long k)
{
    long long res = 0;
    if(k < 0)
        return false;
    for(int i = 1; i <= n; ++i)
    {
        a[i] = A[i];
        a[i] += k;
        if(a[i] >= n)
        {
            res = res + (a[i] - (n - 1)) / (n + 1);
            if((a[i] - (n - 1)) % (n + 1))
                ++res;
        }
        if(res > k)
            return false;
    }
    return true;
}

void solve(long long k)
{
    for(int delta = -1000; delta <= 1000; ++delta)
        if(trueCan(k + delta))
        {
            cout << k + delta << '\n';
            return;
        }
}

bool can(long long k)
{
    for(int delta = -1000; delta <= 1000; ++delta)
        if(trueCan(k + delta))
            return true;
    return false;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> A[i];
    }
    long long l = 0;
    long long r = 50 * 1ll * 1e9 * 1ll * 1e7;
    long long ans = -1;
    //cout << can(0);
    while(l <= r)
    {
        long long mid = (l + r) / 2;
        if(can(mid))
        {
            ans = mid;
            r = mid - 1;
        }else
            l = mid + 1;
    }
    solve(ans);

    return 0;
}
/**
4 4
2 5
3 3
1 4
2 2
0 3
1 1
*/
