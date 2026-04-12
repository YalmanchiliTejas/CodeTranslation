#include <cstdio>
#define MAX 15
using namespace std;

int main(){
	int n;
	
	while(scanf("%d", &n) != EOF){
		int array[MAX][MAX];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				array[i][j] = 0;
	
		int j = n / 2 + 1, k = n / 2;
		for(int i = 1; i <= n * n; i++){
			if(j >= n) j = 0;
			if(k >= n) k = 0;
			if(array[j][k] > 0){
				j++;
				k--;
				if(j >= n) j = 0;
				if(k >= n) k = 0;
				if(j < 0)  j = n - 1;
				if(k < 0)  k = n - 1;
				array[j][k] = i;
				j++;
				k++;
				continue;
			}
			array[j][k] = i;
			j++;
			k++;
		}
	
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				printf("%4d", array[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}