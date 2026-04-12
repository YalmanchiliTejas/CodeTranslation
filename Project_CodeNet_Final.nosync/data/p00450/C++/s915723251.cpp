#include<cstdio>
#include<string>
#include<vector>
#include<sstream>
#include<deque>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,n) for(int i=1;i<=n;i++)

class S{
	public:
	S(){cont=0;}
	int col;
	int cont;
};

S ret[10001];

int main(){
	while(1){
		int now=0;
		int n;
		scanf("%d",&n);
		if(n==0)break;
		int a;
		scanf("%d",&a);
		ret[now].col=a;
		ret[now].cont=1;
		now++;
		
		for(int i=2;i<=n;i++){
			/*
			rep(j,now){
				rep(k,ret[j].cont){
					printf("[%d]",ret[j].col);
				}
			}puts("");
			*/
			
			scanf("%d",&a);
			
			if(i%2==1){
				if(ret[now-1].col==a){
					ret[now-1].cont++;
				}else{
					ret[now].col=a;
					ret[now].cont=1;
					now++;
				}
			}else{
				if(ret[now-1].col==a){
					ret[now-1].cont++;
				}else{
					if(now-2>=0){
						ret[now-2].cont+=ret[now-1].cont+1;
						now--;
					}else{
						ret[now-1].col=a;
						ret[now-1].cont++;
					}
				}
			}
		}
		/*
		rep(j,now){
			rep(k,ret[j].cont){
				printf("[%d]",ret[j].col);
			}
		}puts("");
		*/
		int ans=0;
		rep(j,now){
			rep(k,ret[j].cont){
				if(ret[j].col==0){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
}