#include <bits/stdc++.h>
using namespace std;
bool cmp(long long int r,long long int t)
{
    return r>t;
}
int main()
{
    long long int a[60];
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%lld",&a[i]);
    }

    long long int ss=0;
    for(int j=0;; j++)
    {
        long long int s=0;
        sort(a,a+n,cmp);
        if(a[0]<n)
        {
            printf("%lld\n",ss);
            break;
        }
        else
        {
            s+=a[0]/n;
            ss+=s;
            a[0]=a[0]%n;

            for(int i=1; i<n; i++)
            {
                a[i]+=s;
            }
        }
    }
    return 0;
}
