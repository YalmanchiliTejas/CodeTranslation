#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int n;
long long int k;

long long int h[52];
long long int p[52];
long long int pat(int lv, long long int shf);

int main()
{
scanf("%d %lld",&n,&k);
p[0]=1;
h[0]=1;
for(int i=1;i<=50;i++)
{
h[i]=h[i-1]*2+3;
p[i]=p[i-1]*2+1;
}
long long int ans=0;
if(k==h[n]){k--;}
if(k<=1+h[n-1])
{
ans=pat(n-1,k-1);
}
else{ans= p[n-1]+1+pat(n-1,k-2-h[n-1]); }
printf("%lld\n",ans);

}

long long int pat (int lv, long long int shf)
{
if(lv==0){if(shf==1){return 1;} else{return 0;}}
if(shf==h[lv]){shf--;}
long long int get;
if(shf==0){get=0;}
else if(shf<=1+h[lv-1]){get= pat(lv-1, shf-1);}
else
{
get = p[lv-1] + pat(lv-1, shf-h[lv-1]-2) +1;
}
return get;
}