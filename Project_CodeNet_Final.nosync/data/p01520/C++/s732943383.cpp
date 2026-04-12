#include<cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,T,e; scanf("%d%d%d",&n,&T,&e);
	rep(i,n){
		int x; scanf("%d",&x);
		for(int k=1;k<10000;k++) if(T-e<=k*x && k*x<=T+e){ printf("%d\n",i+1); return 0; }
	}
	puts("-1");
	return 0;
}