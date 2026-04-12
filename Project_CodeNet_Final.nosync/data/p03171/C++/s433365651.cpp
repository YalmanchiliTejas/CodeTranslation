#include <iostream>
#include <cstdio>

using namespace std;

long long a[3001],n,s[3001];
long long f[3001][3001];

int main()
{
    //freopen("INPUT.TXT","r",stdin);
    //freopen("OUTPUT.TXT","w",stdout);
    cin>>n;
    for(long long i=1; i<=n; ++i) cin>>a[i];
    s[0]=0;
    s[1]=a[1];
    for(long long i=2; i<=n; ++i) s[i]=s[i-1]+a[i];
    for(long long i=1; i<=n; ++i) f[i][i]=a[i];
    for(long long i=n-1; i>=1; --i) {
        for(long long j=i+1; j<=n; ++j)
            if (abs(i-j)==1) f[i][j]=max(a[i],a[j]);
            else f[i][j]=(s[j]-s[i-1])-min(f[i+1][j],f[i][j-1]);
    }
//    for(long long i=1; i<=n; ++i) {
//        for(long long j=1; j<=n; ++j)
//            cout<<f[i][j]<<" ";
//        cout<<"\n";
//    }
    cout<<f[1][n]*2-s[n];
    return 0;
}
