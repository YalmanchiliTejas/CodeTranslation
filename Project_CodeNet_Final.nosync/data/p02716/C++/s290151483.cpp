#include<iostream>
using namespace std;
long long max(long long x,long long y)
{
     if(x>y) return x;
     return y;
}
long long a[200010],n,f[200010][3][2],inf=1999999999,ans;
int main()
{
    int i;
    cin>>n;
    inf=inf*-inf;
    for(i=1;i<=n;i++) 
    {
        cin>>a[i];
        if(i-2>=0) f[i][0][0]=f[i-2][0][0]+a[i];
        else f[i][0][0]=a[i];
        f[i][1][0]=inf;
        if(i-2>=0) f[i][1][0]=max(f[i][1][0],f[i-2][1][0]+a[i]);
        if(i-3>=0) f[i][1][0]=max(f[i][1][0],f[i-3][0][0]+a[i]);
        f[i][0][1]=inf;
        if(i-2>=0) f[i][0][1]=max(f[i][0][1],f[i-2][0][1]+a[i]);
        if(i-4>=0) f[i][0][1]=max(f[i][0][1],f[i-4][0][0]+a[i]);
        f[i][2][0]=inf;
        if(i-2>=0) f[i][2][0]=max(f[i][2][0],f[i-2][2][0]+a[i]);
        if(i-3>=0) f[i][2][0]=max(f[i][2][0],f[i-3][1][0]+a[i]);
    }
    ans=inf;
    if(n%2==0) ans=max(max(f[n][0][0],f[n][1][0]),f[n-1][0][0]);
    else
    {
        if(f[n-2][0][0]>ans) ans=f[n-2][0][0];
        if(f[n-1][0][0]>ans) ans=f[n-1][0][0];
        if(f[n-1][1][0]>ans) ans=f[n-1][1][0];
        if(f[n][0][0]>ans) ans=f[n][0][0];
        if(f[n][1][0]>ans) ans=f[n][1][0];
        if(f[n][2][0]>ans) ans=f[n][2][0];
        if(f[n][0][1]>ans) ans=f[n][0][1];
    }
    cout<<ans;
    cin>>i;
    return 0;
}
    
