#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



char buf[4];

int main(){

	int A = 0,B = 0;

	scanf("%s",buf);

	for(int i = 0; i < 3; i++){
		if(buf[i] == 'A'){

			A++;
		}else{

			B++;
		}
	}

	if(A > 0 && B > 0){

		printf("Yes\n");
	}else{

		printf("No\n");
	}

	return 0;
}
