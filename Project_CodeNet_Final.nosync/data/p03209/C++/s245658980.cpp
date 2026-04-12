#include <iostream>
using namespace std;

#define ll long long int

ll P[55], S[55];

ll calc(int N, ll X)
{
    if (!X) return(0);
    if (X == S[N]) return(P[N]);
    ll mid = (S[N] + 1) / 2;
    if (X < mid) return(calc(N - 1, X - 1));
    if (X == mid) return(1 + P[N - 1]);
    return(P[N - 1] + 1 + calc(N - 1, X - S[N - 1] - 2));
}

int main()
{
    int N;
    ll X;
    cin >> N >> X;
    P[0] = S[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        P[i] = 2 * P[i - 1] + 1;
        S[i] = 2 * S[i - 1] + 3;
    }
    cout << calc(N, X) << '\n';
    return(0);
}