#include <stdio.h>

int counter[101] = {0};

int main(){
	int e;
	for(int i = 0; i < 12;i++){
		scanf("%d",&e);
		counter[e]++;
	}
	bool ok = true;
	for(int i = 1; i <= 100; i++){
		if(counter[i] % 4 != 0){
			ok = false;
		}
	}
	printf("%s\n", ok ? "yes" : "no");
	return 0;
}

