#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 103005, SQ = 600;
int n, A[N];
ll S[N], P[SQ][N];
vector < int > D[N];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; i ++)
        for (int j = i; j <= n; j += i)
            D[j].push_back(i), S[i] += A[j];
    for (int i = 1; i < SQ; i++)
        for (int j = n - 1; ~ j; j--)
            P[i][j] = P[i][j + i] + A[j];
    ll Mx = 0;
    for (int a = 1; a < n; a ++)
    {
        for (int &d : D[n - a])
            S[d] -= A[n - a];
        for (int d : D[n - 1 - a])
        {
            if (d >= a)
                break;
            if (a % d == 0 && a + a - d < n - 1)
                continue;
            if (d >= SQ)
            {
                ll sum = 0;
                for (int i = a; i < n - a; i += d)
                    sum += A[i];
                Mx = max(Mx, sum + S[d]);
            }
            else
                Mx = max(Mx, P[d][a] + S[d]);
        }
    }
    return !printf("%lld\n", Mx);
}