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


enum ORDER{
	PLUS,
	HALF,
};

int x[200000],y[200000],z[200000];

int main(){

	int N;
	scanf("%d",&N);

	int a,d;
	scanf("%d %d",&a,&d);

	int M;
	scanf("%d",&M);

	for(int i = 0; i < M; i++){
		scanf("%d %d %d",&x[i],&y[i],&z[i]);
		y[i]--;
		z[i]--;
	}

	int loc;
	scanf("%d",&loc);
	loc--;

	stack<ORDER> S;

	for(int i = M-1; i >= 0; i--){

		switch(x[i]){
		case 0:
			if(loc >= y[i] && loc <= z[i]){
				loc = z[i]-(loc-y[i]);
			}
			break;
		case 1:
			if(loc >= y[i] && loc <= z[i]){
				S.push(PLUS);
			}
			break;
		case 2:
			if(loc >= y[i] && loc <= z[i]){
				S.push(HALF);
			}
			break;
		}
	}

	int ans = a+loc*d;

	while(!S.empty()){

		if(S.top() == PLUS){
			ans++;
		}else{
			ans /= 2;
		}

		S.pop();
	}

	printf("%d\n",ans);

	return 0;
}

