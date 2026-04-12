#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;

int main()
{
int n;
long long int a[200005];
long long int sum=0;
long long int ans=0;
int md=1000000007;
scanf("%d",&n);
for(int i=0;i<n;i++)
{
scanf("%lld",&a[i]);
sum+=a[i];
}
sum=sum%md;

for(int i=0;i<n-1;i++)
{
sum=sum-a[i];
sum=(sum+md)%md;
ans=ans+sum*a[i];
ans=ans%md;
}
printf("%lld",ans);

}