#include <bits/stdc++.h>
using namespace std;

unsigned long long L(unsigned long long N)
{
    return pow(2, N + 2) - 3;
}

unsigned long long P(unsigned long long N)
{
    return pow(2, N + 1) - 1;
}

unsigned long long f(unsigned long long N, unsigned long long X)
{
    if (X == 0)
    {
        return 0;
    }

    if (N == 0)
    {
        if (X == 0)
        {
            return 0;
        }
        else if (X == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (X > (L(N) + 1) / 2)
    {
        return P(N) - f(N, L(N) - X);
    }
    else if (X == (L(N) + 1) / 2)
    {
        return (P(N) + 1) / 2;
    }
    else
    {
        return f(N - 1, X - 1);
    }
}

int main()
{
    unsigned long long N, X;
    cin >> N >> X;
    cout << f(N, X) << endl;
}
