#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 100005

int main(){

	int N;
	scanf("%d",&N);

	char A[2],B[2],current[2];

	scanf("%s %s",A,B);

	bool is_T = (B[0] == 'T') || (A[0] == 'F');

	for(int i = 2; i < N; i++){

		scanf("%s",current);

		if(current[0] == 'T'){

			is_T = true;

		}else{

			if(is_T){

				is_T = false;
			}else{

				is_T = true;
			}
		}
	}

	if(is_T){

		printf("T\n");

	}else{

		printf("F\n");
	}

	return 0;
}

