#include <stdio.h>

int A = 0;
int d;
bool ng = false;

int main(){
	scanf("%d", &A);
	int get;
	int ward = 0;
	int back = 0;
	int now;
	for(int i = 0; i < A; i++){
		scanf("%d", &d);
		if( ng ) continue;
		if( ward < i ){
			ng = true;
		}
		get = i + d / 10;
		if( ward < get){
			ward = get;
		}
		get = i - d / 10;
		if( back >= get ){
			back = i;
		}
	}

	if(back != A-1){
		ng = true;
	}


	if(ng){
		printf("no\n");
	}else{
		printf("yes\n");
	}

	return 0;
}
