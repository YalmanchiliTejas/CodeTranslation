#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	int N;
	scanf("%d",&N);
	if(N&1){
		for(int i=1;i<=N;i++){
			scanf("%d",a+i);
		}
		for(int i=N&1?N:N-1;i>=1;i-=2){
			printf("%d ",a[i]);
		}
		for(int i=2;i<=N;i+=2){
			printf("%d ",a[i]);
		}
		puts("");
	}else{
		for(int i=1;i<=N;i++){
			scanf("%d",a+i);
		}
		for(int i=N&1?N-1:N;i>=2;i-=2){
			printf("%d ",a[i]);
		}
		for(int i=1;i<=N;i+=2){
			printf("%d ",a[i]);
		}
		puts("");
	}
	return 0;
}