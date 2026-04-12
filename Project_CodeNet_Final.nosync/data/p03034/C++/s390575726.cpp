#include <iostream>
#include <cstdio>
using namespace std;
int n;long long d=0,v[10000000],ju[10000000];
void readdata()
{
    cin>>n;
    for (int i=0;i<=n;i++)
    {
        cin>>v[i];
    }
}

int gcd(int u,int v)
{
    while (v != 0) {
        int r = u % v;
        u = v;
        v = r;
    }
    return u;
}

void solve()
{
    long long max1=0;
    for (int i=1;i<=n-1;i++)
    {
        int a;
        int k=0;
        long long sum=0;
        while (1)
        {
            a=n-1-k*i;
            if (a<=i) break;
            sum+=v[i*k]+v[n-1-k*i];
            if (!((a%i==0)&&((a/i-1)*i+a<n-1)))
                max1=max(max1,sum);
            k++;
        }
    }
    cout<<max1;
}

void vet()
{
    int max1=0;
    for (int a=1;a<=n-1;a++)
    {
        for (int b=1;b<a;b++)
        {
            int step=0;
            d++;
            int sum=0;
            while (step<=n-1)
            {
                step+=a;
                sum+=v[step];
                ju[step]=d;
                if (step>n-1)
                {
                    sum=0;
                    break;
                }
                else
                {
                    if (step==n-1) break;
                }
                step-=b;
                if (ju[step]==d)
                {
                    sum=0;
                    break;
                }
                sum+=v[step];
            }
            max1=max(max1,sum);
        }
    }
    cout<<max1;
}

int main()
{
   // freopen("a.inp","r",stdin);
    //freopen("a.out","w",stdout);
    readdata();
    //vet();
    solve();
    return 0;
}
