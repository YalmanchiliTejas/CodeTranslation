#include<bits/stdc++.h>
using namespace std;
const int N=100010;

struct E{
	int t,xt;
}e[N<<1];

int h[N],cnt;

void adge(int f,int t){
	e[++cnt]=(E){t,h[f]};h[f]=cnt;
}

int dp[N][2],dan[N];

void dfs1(int u,int fa){
	
	for(int i=h[u];~i;i=e[i].xt) if(e[i].t!=fa){
		dfs1(e[i].t,u);
	//	printf("u=%d e[i].t=%d\n",u,e[i].t);
		
		if(dan[e[i].t]) dp[u][1]++;
		else dp[u][0]++;
	}
	if(dp[u][1]+dp[u][0]==0){
		dan[u]=1;
	}
	else if(dp[u][1]>1){
			puts("First");
			exit(0);
	}
	else if(dp[u][1]==1){
		dan[u]=0;
	}
	else if(dp[u][1]==0){
		dan[u]=1;
	}
}
			
void dfs2(int u,int fa){
	if(dp[u][1]!=1){
	//	printf("dp(%d,1)=%d\n",u,1);
		puts("First");
		exit(0);
	}
	for(int i=h[u];~i;i=e[i].xt) if(e[i].t!=fa){
		int t[2];
		t[0]=dp[u][0]-(!dan[e[i].t]);
		t[1]=dp[u][1]-dan[e[i].t];
		if(t[1]+t[0]==0){
			dp[e[i].t][1]++;
		}
		else if(t[1]==1){
			dp[e[i].t][0]++;
		}
		else if(t[1]==0){
			dp[e[i].t][1]++;
		}
		dfs2(e[i].t,u);	
	}
}
		
int main(){
	memset(h,cnt=-1,sizeof(h));
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		adge(a,b);
		adge(b,a);
	}
	dfs1(1,1);
	
//	for(int i=1;i<=n;i++) printf("dp(%d)= %d %d\n",i,dp[i][1],dp[i][0]);cout<<endl;
	
	dfs2(1,1);
	
//	for(int i=1;i<=n;i++)  printf("dp(%d)= %d %d\n",i,dp[i][1],dp[i][0]);cout<<endl;
	
	puts("Second");
	return 0;
}

/*
11
1 2
2 6
1 3
3 4
4 5
6 7
6 8
8 10
7 9
9 11
*/