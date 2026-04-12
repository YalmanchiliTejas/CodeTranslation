#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

int table[100000];

int main(){

	int N;
	scanf("%d",&N);

	int maximum = 0;

	for(int i = 0; i < N; i++){
		scanf("%d",&table[i]);
		maximum = max(maximum,table[i]);
	}

	vector<int> V;

	for(int i = 1; i <= maximum; i++){
		if(maximum%i == 0)V.push_back(i);
	}

	int ans = 0,index;

	for(int i = 0; i < N; i++){

		for(index = 0; V[index] < table[i]; index++);
		ans += V[index]-table[i];
	}

	printf("%d\n",ans);

	return 0;
}