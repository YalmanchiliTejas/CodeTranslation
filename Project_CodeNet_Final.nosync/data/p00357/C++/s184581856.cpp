#include <cstdio>
#include <algorithm>
using namespace std;

int N,d[300000];

bool can(){
	int l = d[0];
	for(int i = 1; i < N; i++){
		if(l < i*10){
			return false;
		}
		if(l < i*10+d[i]){
			l = i*10+d[i];
		}
	}
	return true;
}

int main(){
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		scanf("%d",&d[i]);
	}
	if(can()){
		reverse(d,d+N);
		if(can()){
			printf("yes\n");
			return 0;
		}
	}
	printf("no\n");

	return 0;
}