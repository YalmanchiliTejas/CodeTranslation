#include<stdio.h>
#include<algorithm>
using namespace std;
int UF[1000000];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);
	if(a==b)return;
	UF[a]+=UF[b];
	UF[b]=a;
}
int mod=1000000007;
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b),a){
		for(int i=0;i<a;i++)UF[i]=-1;
		for(int i=0;i<b;i++){
			int c,d;
			scanf("%d%d",&c,&d);
			c--;d--;
			UNION(c,d);
		}
		int count=0;
		for(int i=0;i<a;i++){
			if(UF[i]<0)count++;
		}
		int ret=1;
		for(int i=0;i<count;i++)ret=ret*2%mod;
		if(count!=a)ret=(ret+1)%mod;
		printf("%d\n",ret);
	}
}