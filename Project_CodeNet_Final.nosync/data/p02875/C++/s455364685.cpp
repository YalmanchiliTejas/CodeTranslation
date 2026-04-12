#include <iostream>
#include <vector>
using namespace std;

long long powmod(long long a, long long b, long long m)
{
    long long r = 1;
    for (; b>0; b>>=1, a=a*a%m)
        if (b&1)
            r = r*a%m;
    return r;
}

long long inv(long long a, long long m)
{
    return powmod(a, m-2, m);
}

int main()
{
    long long N;
    cin>>N;

    long long M = 998244353LL;

    vector<long long> F(N+1);
    F[0] = 1;
    for (int i=1; i<=N; i++)
        F[i] = F[i-1]*i%M;

    long long t = 0;
    for (long long i=N/2+1; i<=N; i++)
    {
        t += 2*powmod(2, N-i, M)*F[N]%M*inv(F[i], M)%M*inv(F[N-i], M)%M;
        t %= M;
    }
    cout<<((powmod(3, N, M)-t)%M+M)%M<<endl;
}
