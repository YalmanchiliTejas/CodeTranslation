#include<stdio.h>

int main(){
	int n,h[21]={0},ans=0,max=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	for(int i=1;i<=n;i++){
		if(max<=h[i]){
			ans++;
			max=h[i];
		}
			
	}
	
	printf("%d\n",ans);
	return 0;
}