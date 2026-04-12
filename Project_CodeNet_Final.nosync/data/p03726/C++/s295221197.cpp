#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define INF 1000000
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
vector<int> G[100001];
bool used[100001];

int dfs(int v){
	int cnt=0;
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		if(!used[G[v][i]])cnt+=dfs(G[v][i]);
	}
	if(cnt==0)return 1;
	if(cnt==1)return 0;
	return 2;
}

int main(void){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	printf("%s\n",dfs(0)!=0?"First":"Second");
	return 0;
}
