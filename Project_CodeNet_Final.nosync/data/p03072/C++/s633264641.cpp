#include <cstdio>

int main(){
	int n,h[20],ans;

	ans=1;

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&h[i]);
	}

	for(int i=1;i<n;i++){
		for(int k=0;k<i;k++){
			//printf("[%d,%d]%d-%d\n",i,k,h[i],h[k]);
			if(h[i]<h[k]){
				//printf("no\n");
				break;
			}
			if(i==k+1){
				//printf("+\n");
				ans++;
			}
		}
	}
	printf("%d\n",ans);
}