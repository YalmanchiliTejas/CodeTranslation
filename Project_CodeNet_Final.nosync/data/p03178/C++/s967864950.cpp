#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
int main()
{
    string s;
    long long d;
    cin >> s >> d;
    long long n=s.size();
    long long a[100001];
    for(long long i=0;i<n;i++)
    {
        a[i]=s[i]-'0';
    }
    long long f[100005][105][2];
    memset(f,0,sizeof(f));
    f[0][0][1]=1;
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<d;j++)
        {
            f[i+1][(j+a[i])%d][1]+=f[i][j][1];
            f[i+1][(j+a[i])%d][1]%=mod;
            for(long long k=0;k<a[i];k++)
            {
                f[i+1][(j+k)%d][0]+=f[i][j][1];
                f[i+1][(j+k)%d][0]%=mod;
            }
            for(long long k=0;k<10;k++)
            {
                f[i+1][(j+k)%d][0]+=f[i][j][0];
                f[i+1][(j+k)%d][0]%=mod;
            }
        }
    }
    cout << (f[n][0][0]+f[n][0][1]-1+mod)%mod;
    return 0;
}
