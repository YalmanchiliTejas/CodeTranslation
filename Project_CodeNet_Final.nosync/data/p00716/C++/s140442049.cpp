#include<cstdio>
#include<algorithm>

using namespace std;

int M,y,n,m;
int a,c;
double b;
int main(void){
	scanf("%d",&M);
	for(int ddd=0;ddd<M;ddd++){
		scanf("%d",&m);
		scanf("%d",&y);
		scanf("%d",&n);
		int res=m;
		for(int i=0;i<n;i++){
			scanf("%d %lf %d",&a,&b,&c);
			if(a==1){
				int nd=m;
				for(int j=0;j<y;j++){
					nd+=nd*b;
					nd-=c;
				}
				res=max(res,nd);
			}else{
				int nd=m,ndd=0;
				for(int j=0;j<y;j++){
					ndd+=nd*b;
					nd-=c;
				}
				res=max(res,nd+ndd);
			}
		}
		printf("%d\n",res);
	}
	return 0;
}