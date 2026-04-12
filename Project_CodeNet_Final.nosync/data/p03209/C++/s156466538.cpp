#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
long long a[55];
long long f[8]={0,0,1,2,3,3};
long long ans;
long long b[55];
long long updata(long long n,long long x)
{
    if(n==1)
    {
        ans+=f[x];
        return f[x];
    }
    else
    {
        if(x>((a[n]+1)/2))
        {
            if(b[n-1]==-1)
            b[n-1]=updata(n-1,a[n-1]);
            if(x!=a[n])
            return b[n-1]+updata(n-1,x-((a[n]+1)/2))+1;
            else
            return b[n-1]+updata(n-1,a[n-1])+1;
        }
        else if(x==(a[n]+1)/2)
        {
            return updata(n-1,a[n-1])+1;
        }
        else
        {
            return updata(n-1,x-1);
        }
    }
}
int main(int argc, char *argv[])
{
    long long n,x;
    cin>>n>>x;
    a[1]=5;
    memset(b,-1,sizeof(b));
    for(int i=2;i<=n;i++)
    {
        a[i]=a[i-1]*2+3;
    }
    ans=0;
    cout<<updata(n,x)<<endl;
    //cout<<ans+(n-1)<<endl;
	return 0;
}
