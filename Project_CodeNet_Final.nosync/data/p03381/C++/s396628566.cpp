//ARC 095 C
#include <cstdio>
#include <algorithm>
using namespace std;
int x[200010],n,m1,m2,y[200010];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x[i]);
		y[i]=x[i];
	}
	sort(x,x+n);
	m1=x[n/2];
	m2=x[n/2-1];
	for(int i=0;i<n;i++)
		printf("%d\n",y[i]>m2?m2:m1);
}