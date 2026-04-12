#include <cstdio>
#include <algorithm>
using std::sort;
 
const int MAXN =200000;
 
void new_exclude(int *a,int N)
{
	int i,b[MAXN];
	for(i=0;i<N;i++)
		b[i]=a[i];
	sort(b,b+N);
	
	for(i=0;i<N;i++){
		if(a[i]<b[N/2])
			printf("%d\n",b[N/2]);
		else
			printf("%d\n",b[N/2-1]);
	}
 
}
 
 
int main(void)
{
	
	int i,N,a[MAXN];
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d",a+i);
 
	new_exclude(a,N);
	return 0;
 
}
 
 