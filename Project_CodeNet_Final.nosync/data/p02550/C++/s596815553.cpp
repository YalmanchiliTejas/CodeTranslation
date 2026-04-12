#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

ll powmod(ll x, ll k, ll m)
{
    ll ret = 1;
    for (ll i = 0; i < k; i++)
    {
        ret = (ret * x) % m;
    }
    return ret;
}

int main(void)
{
    ll N, X, M;
    cin >> N >> X >> M;

    ll A = X;
    ll ans = X;
    ll array[M];
    for (int i = 1; i < N; i++)
    {
        A = powmod(A, 2, M);
        for (int j = 1; j < i; j++)
        {
            if (array[j] == A)
            {
                ll sum = 0;
                for (int k = j; k < i; k++)
                {
                    sum = sum + array[k];
                }
                ans = ans + (sum * ll((N - i) / (i - j)));
                for (int k = 0; k < ((N - i) % (i - j)); k++)
                {
                    ans = ans + array[j + k];
                }
                A = 0;
                break;
            }
            else
            {
                array[i] = A;
            }
        }
        if (A == 0)
        {
            break;
        }
        ans = ans + A;
    }

    cout << ans << "\n";
}
