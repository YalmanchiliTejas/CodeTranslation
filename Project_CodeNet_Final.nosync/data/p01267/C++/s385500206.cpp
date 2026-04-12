#include<cstdio>

using namespace std;

int main(){
	for(int n,a,b,c,x;scanf("%d%d%d%d%d",&n,&a,&b,&c,&x),n;){
		int y[100];
		for(int i=0;i<n;i++)	scanf("%d",y+i);

		bool ok=false;
		int t,pos=0;
		for(t=0;t<=10000;t++){
			if(x==y[pos])	pos++;
			if(pos==n){ ok=true; break; }
			x=(a*x+b)%c;
		}
		if(ok)	printf("%d\n",t);
		else	puts("-1");
	}

	return 0;
}