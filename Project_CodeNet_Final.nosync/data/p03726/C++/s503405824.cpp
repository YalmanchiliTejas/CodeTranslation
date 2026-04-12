#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> m[100005];
int n,u,v;
int dfs(int pos,int pre){
    int len=m[pos].size(),ans=0;
    for(int i=0;i<len;i++)
        if(m[pos][i]!=pre) ans+=dfs(m[pos][i],pos);
	if(ans>=2){
        printf("First\n");
        exit(0);
    }
    else if(ans==0) return 1;
    else return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        m[u].push_back(v);
        m[v].push_back(u);
    }
    if(dfs(1,-1)) printf("First\n");
    else printf("Second\n");
    return 0;
}