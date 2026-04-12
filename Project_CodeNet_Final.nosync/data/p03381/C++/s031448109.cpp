#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
long long n,x[200000],y[200000],i,a,b;
int main()
{
    cin >> n;
    for(i=0;i<n;i++){
        cin >> x[i];
        y[i]=x[i];
    }
    sort(y,y+n);
    a=y[n/2-1];
    b=y[n/2];
    for(i=0;i<n;i++){
        if(x[i]>=b)printf("%lld\n",a);
        else printf("%lld\n",b);
    }
}