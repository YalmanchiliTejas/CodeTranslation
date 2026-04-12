//_nebula_
#include<bits/stdc++.h>
using namespace std;
#define int long  long
#define double long double
int t;
const int M=1e9+7;
int factt(int n)
{
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans*=i;
        ans=ans%M;
    }
    return ans;
}
int max(int a,int b,int c)
{
    return max(a,max(b,c));
}
int min(int a,int b,int c)
{
    return min(a,min(b,c));
}
int fspow(int x,int y)
{
    int ans;
    if(y==0) return 1;
    ans=fspow(x, y/2);
    if(y%2==0) return (ans*ans)%M;
    return (x*((ans*ans)%M))%M;;
}
int gcd(int x,int y)
{
    if(x<y) swap(x,y);
    if(y==0) return x;
    return gcd(x%y,y);
}
int p2(int x)
{
    int ans=0;
    while(x>=1)
    {
        ans++;
        x/=2;
    }
    return ans;
}
int v=0;
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    t=1;
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //  cin>>t;
    // int tmp=t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            sum-=a[i];
            ans=(ans+(a[i]%M)*(sum%M))%M;
        }
        cout<<ans<<"\n";
    }
}
