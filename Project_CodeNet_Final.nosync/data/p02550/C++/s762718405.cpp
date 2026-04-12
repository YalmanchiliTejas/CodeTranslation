#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N, X, M;
    cin >> N >> X >> M;

    vector<long long> seen(M);
    for (long long i = 0; i < M; i++)
    {
        seen[i] = 0;
    }

    long long x = X;
    long long A;
    long long count = 0;
    long long preans = x;
    while(1)
    {
        if (seen[x] == 1)
        {
            break;
        }
        if (count == N-1)
        {
            cout << preans << endl;
            exit(0);
        }
        seen[x] = 1;    
        A = ((long long)pow(x, 2)) % M;
        preans += A;
        x = A;
        count++;
        
    }

    N = N-count-1;
    long long ans = 0;
    ans += preans;
    x = A;
    count = 0;
    preans = 0;
    for (long long i = 0; i < M; i++)
    {
        seen[i] = 0;
    }
    while(1)
    {
        if (seen[x] == 1)
        {
            break;
        }
        if (count == N)
        {
            cout << ans+preans << endl;
            exit(0);
        }
        seen[x] = 1;
        A = ((long long)pow(x, 2)) % M;
        preans += A;
        x = A;
        count++;
    }

    ans += (N / count) * preans;
    for (long long i = 0; i < N % count; i++)
    {
        A = ((long long)pow(x, 2)) % M;
        ans += A;
        x = A;
    }
    cout << ans << endl;
}