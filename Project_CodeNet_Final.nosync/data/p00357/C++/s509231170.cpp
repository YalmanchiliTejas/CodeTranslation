#include <string>
#include <stdio.h>
#include <vector>

int A = 0;
int d[300000] = {};
bool ok = false;

int main(){
	scanf("%d", &A);
	for(int i = 0; i < A; i++){
		scanf("%d", &(d[i]));
	}

	int ck = 0;
	int get = 0;
	for(int i = 0; i <= ck; i++){
		if(i == A){
			ok = true;
			break;
		}
		get = i + d[i]/10;
		if( ck < get ){
			ck = get;
		}

	}
	if ( ok ){
	ok = false;
	ck = A-1;
	for(int i = A-1; i >= ck; i--){
		if(i == -1){
			ok = true;
			break;
		}
		get = i - d[i]/10;
		if( ck > get ){
			ck = get;
		}

	}
	}
	if(ok){
		printf("yes\n");
	}else{
		printf("no\n");
	}

	return 0;
}
