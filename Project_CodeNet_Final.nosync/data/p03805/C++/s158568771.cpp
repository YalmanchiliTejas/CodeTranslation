#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
bool edge[10][10];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int a,b;
	for(int i=0;i<m;++i){
		scanf("%d%d",&a,&b);
		--a;--b;
		edge[a][b]=edge[b][a]=true;
	}
	int path[10]={0,1,2,3,4,5,6,7,8,9};
	int f=1;
	for(int i=1;i<n;++i)
		f*=i;
	int ans=0;
	for(int i=0;i<f;++i){
		bool chk=true;
		for(int i=1;i<n;++i){
			if(!edge[path[i-1]][path[i]])
				chk=false;
		}
		if(chk)
			++ans;
		next_permutation(path+1,path+n);
	}
	printf("%d",ans);
}
/*

3 3
1 2
1 3
2 3

7 7
1 3
2 7
3 4
4 5
4 6
5 6
6 7

*/