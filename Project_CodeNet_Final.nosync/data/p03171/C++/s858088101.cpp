#include <iostream>

using namespace std;
long long f[3001][3001];
long long a[3001];
long long sum=0;
long long rec(long long l,long long r,long long turn)
{
    if(l>r)return 0;
    if(f[l][r]!=1<<30)return f[l][r];
    if(turn==1)
    {
        long long r1=a[l]+rec(l+1,r,1-turn);
        long long r2=a[r]+rec(l,r-1,1-turn);
        long long rf=max(r1,r2);
        f[l][r]=rf;
        return f[l][r];
    }
    else
    {
        long long r1=-a[l]+rec(l+1,r,1-turn);
        long long r2=-a[r]+rec(l,r-1,1-turn);
        long long rf=min(r1,r2);
        f[l][r]=rf;
        return f[l][r];
    }
}
int main()
{
    long long n;
    cin >> n;
    for(long long i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    for(long long i=0;i<=3000;i++)
    {
        for(long long j=i;j<=3000;j++)
        {
            f[i][j]=1<<30;
        }
    }
    cout << rec(0,n-1,1);
    return 0;
}
