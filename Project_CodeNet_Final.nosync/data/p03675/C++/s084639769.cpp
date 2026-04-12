#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
const int MOD=1e9+7;
int n;
int a[N];
int b[N];
int main()
{

    cin>>n;
   for(int i=1;i<=n;i++)
   {
   	scanf("%d",&a[i]);
   }
   int m=n;
   int j=1;
   for(int i=n;i>=2;i-=2)
   {
   	b[j]=a[i];
   	b[n-j+1]=a[i-1];
   	j++;
   }
   if(n&1)
   {
   	b[j]=a[1];
   }
   
   for(int i=1;i<=n;i++)
   	printf("%d ",b[i]);
   
    return 0;

}
