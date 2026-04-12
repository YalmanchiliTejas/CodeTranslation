#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
char sa[1005][1005],s[1005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		for(int j = 1; j <= m; j++){
			sa[i][j] = s[j];
		}	
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(sa[i][j] == '#'){
				if(sa[i-1][j] == '#' && sa[i][j-1] == '#'){
					printf("Impossible");
					return 0;
				}else if(sa[i+1][j] == '#' && sa[i][j+1] == '#'){
					printf("Impossible");
					return 0;
				}
			}
	printf("Possible\n") ;
	return 0;
}

/*
###
..#
.#(#)
如果左边的#它不连通起点，则就得向左走才能把它走到
如果左边的#它连通起点，则上面的点如果不连通起点，也存在他同样的问题 
如果上面的点连通起点，则从起点到该点有两条路径，则如果要走完所有的点，一定得回头 
*/