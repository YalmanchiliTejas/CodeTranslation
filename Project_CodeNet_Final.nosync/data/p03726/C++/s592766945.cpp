/*Lucky_Glass*/
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5;
int n;
vector<int> lnk[N+5];
int DFS(int u,int pre){
	int ret=0;
	for(auto v : lnk[u]){
		if(v==pre) continue;
		ret+=DFS(v,u);
	}
	if(ret>=2) return ret;
	return ret^1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		lnk[u].push_back(v);
		lnk[v].push_back(u);
	}
	printf("%s\n",DFS(1,0)?"First":"Second");
	return 0;
}