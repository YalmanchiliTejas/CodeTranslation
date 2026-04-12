#include <iostream>
#include <vector>

using namespace std;

#define int long long

int INF = 1e9 + 7;

int myPow(int n, int m)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
        {
            res *= n;
            res %= INF;
        }
        n = n * n % INF;
        m >>= 1;
    }
    return res;
}

//n^(INF-2)
int invMod(int n)
{
    return myPow(n, INF - 2);
}

vector<int> frac((int)1e6);

void set_frac()
{
    frac[0] = 1;
    for (int i = 1; i < frac.size(); i++)
    {
        frac[i] = frac[i - 1] * i % INF;
    }
}

// nCm = n!/m!/(n-m)!
int comb(int n, int m)
{
    int res = frac[n];
    res = res * invMod(frac[m]) % INF;
    res = res * invMod(frac[n - m]) % INF;
    return res;
}

signed main()
{
    int N, M, K;
    cin >> N >> M >> K;

    int sum_cost = 0;

    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j < N; j++)
        {
            //diag
            sum_cost += (i + j) * (M - i) * (N - j) * 2;
            sum_cost %= INF;
        }
    }

    for (int i = 1; i < N; i++)
    {
        sum_cost += i * M * (N - i);
        sum_cost %= INF;
    }

    for (int i = 1; i < M; i++)
    {
        sum_cost += i * N * (M - i);
        sum_cost %= INF;
    }

    set_frac();
    cout << sum_cost * comb(N * M - 2, K - 2) % INF << endl;
}