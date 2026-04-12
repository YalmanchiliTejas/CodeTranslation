#include<bits/stdc++.h>
using namespace std;
int n,a[30]={};
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int s=1;
	for(int i=2;i<=n;++i){
		bool p=0;
		for(int j=1;j<i;++j)
		 if(a[j]>a[i])p=1;
		if(!p)++s;
	} 
	printf("%d",s);
	return 0;
}