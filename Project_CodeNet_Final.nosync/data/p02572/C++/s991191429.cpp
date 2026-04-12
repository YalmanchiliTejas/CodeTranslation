#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

const int M = 1000000007;
int  N;
long long a[200000],ans,sum,d;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}


int main()
{
    cin >>N;

    int i,j;
    rep0(i,N)
    {
        cin>>j;
        a[i]=j%M;
        sum+=a[i];
        sum%=M;
        d+=a[i]*a[i]%M;
        d%=M;
    }
/*
    rep0(i,N-1){
        rep(i+1,j,N)
        ans+=a[i]*a[j]%M;
        ans%=M;
    }*/
    sum=(sum*sum-d)%M;
    ans=sum*modinv(2,M)%M;
    cout<<ans<<endl;

    return 0;
}