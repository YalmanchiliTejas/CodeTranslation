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
#define EPS 0.0000001
using namespace std;

int main(){

	int N;
	scanf("%d",&N);
	int* table = new int[N];
	int* reverse_table = new int[N];

	for(int i = 0; i < N; i++){
		scanf("%d",&table[i]);
	}

	for(int i = 0; i < N; i++)reverse_table[i] = table[N-1-i];

	int maximum = table[0];
	int index = 0,pre_index;

	while(true){

		pre_index = index;
		index = maximum/10;

		if(pre_index == index)break;

		for(int i = pre_index+1; i <= index; i++){
			maximum = max(maximum,10*i+table[i]);
		}

		if(maximum >= 10*(N-1))break;
	}

	if(maximum < 10*(N-1)){
		printf("no\n");
		return 0;
	}

	maximum = reverse_table[0];
	index = 0;

	while(true){

		pre_index = index;
		index = maximum/10;

		if(pre_index == index)break;

		for(int i = pre_index+1; i <= index; i++){
			maximum = max(maximum,10*i+reverse_table[i]);
		}

		if(maximum >= 10*(N-1))break;
	}

	if(maximum < 10*(N-1)){
		printf("no\n");
		return 0;
	}else{
		printf("yes\n");
	}

	return 0;
}