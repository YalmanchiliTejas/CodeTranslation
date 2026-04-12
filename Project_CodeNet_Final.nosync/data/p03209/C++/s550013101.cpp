#include <bits/stdc++.h>
using namespace std;
vector<long> A(55), P(55);
long f(long n, long x);



int main()
{
    long n, x;
    cin >> n >> x;
    A[0] = 1; P[0] = 1;
    
    for(int i=0; i<n-1; i++)
    {
        A[i+1] = A[i]*2 + 3;
        P[i+1] = P[i]*2 + 1;
    }

    cout << f(n, x);
}

long f(long n, long x)
{
    if(n == 0)
    {
        if(x <= 0) return 0;
        else return 1;
    }
    else if(x <= 1+A[n-1])
    {
        return f(n-1, x-1);
    }
    else
    {
        return P[n-1] + 1 + f(n-1, x-2-A[n-1]);
    }
}
