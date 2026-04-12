#include<cstdio>
int main(){
	int N;
	scanf("%d",&N);
	if(N<15) printf("%d",800*N);
	if(N>=15) printf("%d",800*N-200*(N/15));
	return 0;
}