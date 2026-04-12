#include <bits/stdc++.h>
using namespace std;
#define take freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define speed ios_base::sync_with_stdio(false);
#define int long long
#define endl "\n"
#define maxi 10000007
int maxo=1e9+7;
int sum=0;
#define rof(i,a,b) for(int i=a;i<b;i++)
void solve(int a[],int i,int s,int p,int n)
{
    if(s==2)
    {
        sum=sum%maxo+ p%maxo;
        return;
    }
    for(int j=i;j<n;j++)
    {
        solve(a,j+1,s+1,((p%maxo)*a[j]%maxo)%maxo,n);
    }
}
int32_t main()
{
    speed
    //take
    int n;
    cin>>n;
    int a[n];
    int sum1=0;
    int sum2=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum1+=a[i];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        sum2+=a[i];
        ans=((a[i]%maxo)*((sum1-sum2)%maxo))%maxo+ans%maxo;

    }
    cout<<ans;
}