#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int g[10][10];
int perm[10];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<b;i++){
		int p,q;scanf("%d%d",&p,&q);p--;q--;
		g[p][q]=g[q][p]=1;
	}
	for(int i=0;i<a;i++)perm[i]=i;
	int ret=0;
	do{
		if(perm[0]==0){
			bool ok=true;
			for(int i=0;i<a-1;i++)if(!g[perm[i]][perm[i+1]])ok=false;
			if(ok)ret++;
		}
	}while(next_permutation(perm,perm+a));
	printf("%d\n",ret);
}