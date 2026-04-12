#include<iostream>
#include<cstdio>
using namespace std;
long long n,k;
int main()
{
	cin>>n>>k;
if (k==0)
    {
        cout<<(long long)n*n<<endl;
        return 0;
    }
    int i;
    long long ans=0;
    for (i=1;i<=n;i++)
    {
        //b = i
        if (i<=k) continue;
        int t=n/i;
        ans+=(long long)(i-k)*t;
        ans+=max(n%i-k+1,0ll);
    }
    cout<<ans<<endl;
    return 0;}