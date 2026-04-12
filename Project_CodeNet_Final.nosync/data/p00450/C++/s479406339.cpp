#include<iostream>
#include<cstdio>

#define MAX 100020
using namespace std;

int main(){
	while(true){
		int n;
		int ans = 0;
		int white = 0;
		int black = 0;
		int cont[MAX] = {0,};
		int a[MAX] = {3,};

		scanf("%d", &n);
		
		if( n == 0 )
			break;

		for(int i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
		}

		for(int i = 1; i <= n; ++i){
			if( a[i] == a[i-1] )
				cont[i] = cont[i-1] + 1;
			else
				cont[i] = 1;

			if( i % 2 == 0 && a[i] != a[i-1] ){
				if( a[i] == 0 ){
					white += cont[i-1];
					black -= cont[i-1];
					cont[i] = cont[i-1] + cont[ i-1 - cont[i-1] ] + 1;
				}else{
					white -= cont[i-1];
					black += cont[i-1];
					cont[i] = cont[i-1] + cont[ i-1 - cont[i-1] ] + 1;
				}
			}
			if( a[i] == 0 ){
				++white;
			}else{
				++black;
			}
		}

		printf("%d\n", white);
	}
	return 0;
}