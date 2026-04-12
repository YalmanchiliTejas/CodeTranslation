#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,t[20000];

int main(){
	while(scanf("%d%d",&n,&m),(n|m) != 0){
		for(int i = 0; i < n+m; i++){
			scanf("%d",&t[i]);
		}
		sort(t,t+n+m);
		int mx = t[0];
		for(int i = 1; i < n+m; i++){
			if(mx < t[i] -t[i-1]){
				mx = t[i] - t[i-1];
			}
		}
		printf("%d\n",mx);
	}
	return 0;
}