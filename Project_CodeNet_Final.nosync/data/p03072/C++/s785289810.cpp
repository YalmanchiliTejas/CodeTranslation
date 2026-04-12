#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
int n,h[20];
scanf("%d",&n);
int ans=0;
int max=0;
for(int i=0;i<n;i++)
{
scanf("%d",&h[i]);
if(max<h[i]){max=h[i];}
if(h[i]>=max){ans++;}
}
printf("%d\n",ans);
}