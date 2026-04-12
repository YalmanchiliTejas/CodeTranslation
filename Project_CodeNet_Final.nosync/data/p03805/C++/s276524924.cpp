#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n,m;
	bool edge[8][8];
	scanf("%d %d",&n,&m);
	fill(edge[0],edge[0]+64,false);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		edge[a-1][b-1] = true;
		edge[b-1][a-1] = true;
	}
	int a[n];
	for(int i=0;i<n;i++) a[i] = i;
	int cnt = 0;
	do{
		bool flag = true;
		for(int i=1;i<n;i++){
			if(!edge[a[i-1]][a[i]]) flag = false;
		}
		if(flag) cnt++;
	}while(next_permutation(a+1,a+n));
	printf("%d\n",cnt);
	return 0;
}
