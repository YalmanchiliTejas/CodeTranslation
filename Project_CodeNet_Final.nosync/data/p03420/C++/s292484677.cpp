#include<iostream>
#include<cstdio>
using namespace std;
long long n,k,m,ans;
int main()
{
	cin>>n>>k;
if (k==0)
    {
        cout<<(long long)n*n<<endl;
        return 0;
    }
    
    for (int i=k+1;i<=n;i++)
    {
   
        m=n/i;
        ans+=(long long)(i-k)*m;
        ans+=max(n%i-k+1,0ll);
    }
    cout<<ans<<endl;
    return 0;
	}