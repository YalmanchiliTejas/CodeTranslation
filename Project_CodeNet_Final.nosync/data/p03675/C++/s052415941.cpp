#include<bits/stdc++.h>
using namespace std;

int n,l,r;
int a[400010],b[800010];

int main()
{int i,j,k,p;
 
 scanf("%d",&n);
 for(i=1;i<=n;i++) scanf("%d",&a[i]);
 l=400000;
 r=400000;
 b[l]=a[1];
 for(i=2;i<=n;i++)
 	if(i&1)
		b[--l]=a[i];
	else
		b[++r]=a[i];
 //cout<<l<<" "<<r<<endl;		
 if(n&1)
 {	for(i=l;i<=r;i++)
 	{	printf("%d",b[i]);
 		printf("%c",i!=r?' ':'\n');
 	}
 }
 else
 {	for(i=r;i>=l;i--)
 	{	printf("%d",b[i]);
 		printf("%c",i!=l?' ':'\n');
 	}
 }
 
 return 0;
}