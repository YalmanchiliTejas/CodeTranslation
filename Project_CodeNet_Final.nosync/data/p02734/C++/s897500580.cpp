#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int maxn=3000+5;
int n,s;
int a[maxn];
int sum[maxn];
int f[maxn][maxn];
int main()
{
    cin>>n>>s;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]<=s) f[i][a[i]]=i;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=a[i];j<=s;++j)
        {
            f[i][j]=(f[i][j]+sum[j-a[i]])%mod;
        }
        for(int j=0;j<=s;++j) sum[j]=(sum[j]+f[i][j])%mod;
    }
    int an=0;
    for(int i=1;i<=n;++i)
    {
        an=(an+(ll)f[i][s]*(n-i+1))%mod;
    }
    cout<<an<<endl;
    return 0;
}