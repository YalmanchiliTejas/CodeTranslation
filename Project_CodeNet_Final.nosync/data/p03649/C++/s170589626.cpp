#include<iostream>
#include<fstream>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<cmath>
#include<numeric>
#include<ctime>
#include<locale>
//freopen("std.in","r",stdin);freopen("stdout.out","w",stdout);
using namespace std;
long long a[55];
int main()
{
    long long n;
    long long s;
    cin>>n;
    for(long i=0;i<n;i++)scanf("%lld",&a[i]);
    s=0;
    for(long i=0;i<n;)
    {
        if(a[i]>=n)
        {
            if((a[i])/n>=n)
            {
            long long x,y;
            x=a[i]-(a[i]/(n+1)*n);
            y=a[i]/(n+1);
            s+=a[i]/(n+1);
            s+=n*(y-n+1);
            x-=y-n+1;
            if(x>n)
            {
                s+=n+1;
                for(long j=0;j<n;j++)
                {
                    if(i!=j)a[j]+=n-1;
                }
                a[i]=x-n-1;
            }
            else if(x==n)
            {
                s+=n;
                for(long j=0;j<n;j++)
                {
                    if(i!=j)a[j]+=n-2;
                }
                a[i]=n-1;
            }
            else
            {
                for(long j=0;j<n;j++)
                {
                    if(i!=j)a[j]+=n-1;
                }
                a[i]=n-1;
            }
            i=0;
            }
            else
            {
                s+=a[i]/n;
                for(long j=0;j<n;j++)
                {
                    if(i!=j)a[j]+=a[i]/n;
                }
                a[i]%=n;
                i=0;
            }
        }
        else i++;
    }
    cout<<s;
    return 0;
}
