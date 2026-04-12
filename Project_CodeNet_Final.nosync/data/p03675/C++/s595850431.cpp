#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[200005];
int b[200005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
int x=(n-1)/2+1;
int w=0;

for(int i=1;i<=x;i++)
   {
 b[i]=a[n-w];
   w+=2;

}

 w=1;
for(int i=n;i>=x+1;i--)
{

   b[i]=a[n-w];
    w+=2;
}
for(int i=1;i<=n;i++)
    cout<<b[i]<<" ";
    cout<<endl;
return 0;
}
