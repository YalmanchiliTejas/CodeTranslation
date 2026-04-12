#include <iostream>
#include <cstring>
using namespace std;
int N, M, E;
char A[100005], B[100005];
int X2[100005], Fact[100005], rev[100005];
int X[2][100005];

const int MOD = 998244353;
const int Base = 3;
const int lim = 32768;
void Read()
{
    cin.getline(A + 1, 100005);
    cin.getline(B + 1, 100005);
    N = strlen(B + 1);
}
int powLog(int n, int p)
{
    int sol = 1;
    while(p)
    {
        if(p % 2 == 1)
        {
            sol = (1LL * sol * n) % MOD;
        }
        n = (1LL * n * n) % MOD;
        p /= 2;
    }
    return sol;
}
void precalcME()
{
    for(int i = 1; i <= N; i++)
    {
        if(A[i] == '1' && B[i] == '1')
        {
            ++M;
        }
        else
            if(A[i] == '1')
                ++E;
    }
}

void revBit(int P[], int dim)
{
    int lim = (1 << dim);
    for(int i = 0; i < lim; i++)
    {
        int x = i, res = 0, p = dim;
        while(p >= 1)
        {
            res = res * 2 + x % 2;
            x /= 2;
            --p;
        }
        rev[res] = P[i];
    }
    for(int i = 0; i < lim; i++)
    {
        P[i] = rev[i];
        rev[i] = 0;
    }
}
void fft(int P[], int log, bool inverse)
{
    int dim = (1 << log);
    int mask = dim - 1;
    revBit(P, log);

    for(int len = 1; 2 * len <= dim; len *= 2)
    {
        for(int i = 0; i < dim; i += len * 2)
        {
            //step = 1;
            int aux = X[inverse][len * 2];
            //step.setC((cos(PI / dim), sin(PI / dim)));
            /*Complex w;
            w.setC(1, 0);*/
            int w = 1;
            for(int j = 0; j < len; j++)
            {
                int a = P[i + j];
                int b = (1LL * w * P[i + j + len]) % MOD;
                P[i + j] = (a + b);
                if(P[i + j] >= MOD)
                    P[i + j] -= MOD;
                P[i + j + len] = (a - b);
                if(P[i + j + len] < 0)
                    P[i + j + len] += MOD;
                 w = (1LL * w * aux) % MOD;
            }
        }
    }
    if(inverse)
    {
        int inv = powLog(dim, MOD - 2);
        for(int i = 0; i < dim; i++)
            P[i] = (1LL * P[i] * inv) % MOD;
    }
}

void powLogFFT(int P[], int p)
{
    int Sol[200005];
    int log = 0;
    int pw = 1;
    while(pw <= M * 2)
        ++log, pw *= 2;
    for(int i = 0; i < pw; i++)
        Sol[i] = 0;
    Sol[0] = 1;
    while(p)
    {
        if(p % 2 == 1)
        {
            int data[200005];
            for(int i = 0; i < pw; i++)
                data[i] = P[i];
            fft(Sol, log, 0);
            fft(data, log, 0);
            for(int i = 0; i < pw; i++)
                Sol[i] = (1LL * Sol[i] * data[i]) % MOD;
            fft(Sol, log, 1);
           for(int i = M + 1; i < pw; i++)
                Sol[i] = 0;
        }


            fft(P, log, 0);

            for(int i = 0; i < pw; i++)
                P[i] = (1LL * P[i] * P[i]) % MOD;
            fft(P, log, 1);
            for(int i = M + 1; i < pw; i++)
                P[i] = 0;
            p /= 2;
    }
    int sum = 0;
    for(int i = 0; i <= M; i++)
    {
        sum += Sol[i];
        if(sum >= MOD)
            sum -= MOD;
    }
    sum = (1LL * sum * Fact[M]) % MOD;
    sum = (1LL * sum * Fact[M + E]) % MOD;
    sum = (1LL * sum * Fact[E]) % MOD;
    cout << sum << "\n";
}
void precalcFact(int n)
{
    Fact[0] = 1;
    for(int i = 1; i <= max(n, N); i++)
        Fact[i] = (1LL * Fact[i - 1] * i) % MOD;
    for(int i = 0; (1 << i) <= lim * 2; i++)
    {
        X[0][(1 << i)] = powLog(Base, (MOD - 1) / (1 << i));
        X[1][(1 << i)] = powLog(X[0][(1 << i)], MOD - 2);
    }
}
int main()
{
    Read();
    precalcME();
    int power = 1;
    int log = 0;
    int pw = 1;
    while(pw <= M)
        ++log, pw *= 2;
    precalcFact(pw);
    for(int i = 0; i <= M; i++)
        X2[i] = powLog(Fact[i + 1], MOD - 2);
    powLogFFT(X2, E);


    return 0;
}
