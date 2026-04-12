#include <stdio.h>

int main(void){
	int N,i,j,k,l=0;
	scanf("%d",&N);
	int a[N];
	for (i = 0; i < N; i++){
		scanf("%d",&a[i]);
		k = 0;
		if(i != 0){
			for (j = 0;j < i;j++){
			if(a[i] > a[j] || a[i] == a[j]){
		k = k+1;}}}
		if (k == i){
		l = l+1;}}
	printf("%d",l);
	return 0;
}