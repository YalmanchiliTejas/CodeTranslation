#include<bits/stdc++.h>
using namespace std;
const int maxM=(2e5)+5;

long long a[maxM],sp[maxM],f[maxM];
long long n;
long long x,m,dim;
int pos;
int main()
{
    scanf("%lld%lld%lld",&n,&x,&m);
//    printf("%d\n",x);

    a[1]=x;
    f[a[1]]=1;

    dim=1;

    while(dim<n)
    {
        dim++;
        a[dim]=(1LL*a[dim-1]*a[dim-1])%m;
        if(f[a[dim]])
        {
            pos=f[a[dim]];
            dim--;
            break;
        }
            else f[a[dim]]=dim;

    }
   // printf("AM AJUNS AICI");

 //   printf("%d\n",a[1]);

   // printf("%d\n",dim);

   // printf("%d",dim);

    for(int i=1;i<=dim;i++)
    {
        sp[i]=(sp[i-1]+a[i]);
    }

    //printf("%d\n",dim);
    //printf("%d\n",pos);
    //printf("%lld %lld\n",a[pos],a[dim]);


    long long sol=0;

    if(n<=dim) sol=sp[n];
        else
    {
        sol=sp[pos-1];
        int len=dim-pos+1;
        long long add=sp[dim]-sp[pos-1];

        sol=(sol+(n-pos+1)/len*add+sp[pos+(n-pos+1)%len-1]-sp[pos-1]);


    }
    //long long sol=((sp[dim]*(n/dim))+sp[n%dim]);

    printf("%lld\n",sol);



    return 0;
}