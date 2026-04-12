#include<bits/stdc++.h>
using namespace std;
#define modul 1000000007

int main()
{
    int n;
    scanf("%d",&n);
    long long res=0;
    long long a[n];
    long long sum[n]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(i>0)
            sum[0]+=a[i];
        //sum[0]+=a[i];
        //sum[0]=modul;
    }
   // cout<< sum[0]<< " ";
    for(int i=1;i<n-1;i++)
    {

        sum[i]= sum[i-1]-a[i];
        //cout<< sum[i]<< " ";
    }
    cout<< endl;
    for(int i=0;i<n-1;i++)
    {
        res += ((sum[i]%modul)*a[i])% modul;
        res %= modul;
    }
    printf("%lld",res);
}

