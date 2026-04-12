#include<cstdio>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int dfs(int a,int b,int c){
	int res=0;
	if(a>=3) res=max(res,dfs(a-3,b,c)+1);
	if(b>=3) res=max(res,dfs(a,b-3,c)+1);
	if(c>=3) res=max(res,dfs(a,b,c-3)+1);
	if(a>0 && b>0 && c>0) res=max(res,dfs(a-1,b-1,c-1)+1);
	return res;
}

int main(){
	while(1){
		int n[3]={};
		rep(i,6){
			int a; scanf("%d",&a);
			n[i%3]+=a;
		}
		if(n[0]==0 && n[1]==0 && n[2]==0) break;

		int ans=0;
		int n0=min(min(n[0],n[1]),n[2]);
		rep(i,3){
			ans+=(n[i]-n0)/3;
			n[i]-=(n[i]-n0)/3*3;
		}
		ans+=max(n0-3,0);
		rep(i,3) n[i]-=max(n0-3,0);

		printf("%d\n",ans+dfs(n[0],n[1],n[2]));
	}

	return 0;
}