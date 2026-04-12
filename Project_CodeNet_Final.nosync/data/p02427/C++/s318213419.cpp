#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 19


int N;
int POW[SIZE];


int main(){

	POW[0] = 1;
	for (int i = 1; i < SIZE; i++){

		POW[i] = POW[i-1]*2;
	}

	scanf("%d",&N);

	printf("0:\n");
	int index = 1;

	for(int state = 1; state < POW[N]; state++){
		printf("%d:",index++);
		for(int loop = 0; loop < N; loop++){
			if(state & (1 << loop)){
				printf(" %d",loop);
			}
		}
		printf("\n");
	}

	return 0;
}


