#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

struct Info{
	int loc;
};

char T[500001],P[500001];

int main(){

	int T_length,P_length;

	scanf("%s",T);
	for(T_length = 0; T[T_length] != '\0'; T_length++);

	scanf("%s",P);
	for(P_length = 0; P[P_length] != '\0'; P_length++);

	Info* info = (Info*)malloc(sizeof(Info)*P_length);

	int T_loc = T_length-1;

	bool FLG;

	for(int i = P_length-1; i >= 0; i--){
		FLG = false;
		for(int k = T_loc; k >= 0; k--){
			if(T[k] == P[i]){
				info[i].loc = k;
				T_loc = k-1;
				FLG = true;
				break;
			}
		}

		if(!FLG){
			printf("no\n");
			return 0;
		}
	}

	int left,right;

	for(int i = P_length-1; i >=1; i--){
		left = info[i-1].loc+1;
		right = info[i].loc-1;

		if(left > right)continue;

		for(int k = right; k >= left; k--){
			if(T[k] == P[i]){
				printf("no\n");
				return 0;
			}
		}
	}

	for(int i = info[0].loc-1; i >= 0; i--){
		if(T[i] == P[0]){
			printf("no\n");
			return 0;
		}
	}

	printf("yes\n");

	return 0;
}