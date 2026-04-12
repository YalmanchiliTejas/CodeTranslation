#include <ctime>
#include <cstdio>
const int Maxn=100000;
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int deg[Maxn+5];
int root;
int check_dfs(int u,int fa){
	int sum_1=0,sum_2=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		int tmp=check_dfs(v,u);
		if(tmp==1){
			return 1;
		}
		if(tmp==2){
			sum_1++;
		}
		if(tmp==3){
			sum_2++;
		}
	}
	if(sum_1>=2){
		return 1;
	}
	if(sum_1==1){
		return 3;
	}
	return 2;
}
int main(){
	clock_t begin=clock(),end;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
		deg[u]++,deg[v]++;
	}
	if(check_dfs(1,0)!=3){
		puts("First");
	}
	else{
		puts("Second");
	}
	return 0;
	int last=0;
	while(1){
		end=clock();
		if((end-begin)*1.0/CLOCKS_PER_SEC>0.9){
			break;
		}
		root=-1;
		for(int i=last+1;i<=n;i++){
			if(deg[i]!=1){
				root=i;
				break;
			}
		}
		if(root==-1){
			break;
		}
		last=root;
		if(check_dfs(root,0)==1){
			puts("First");
			return 0;
		}
	}
	puts("Second");
	return 0;
}
