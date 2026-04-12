
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


long long int result = 0;
int N;
long long int X;
long long int eatLog[51][2] = {};
//もう食べられない：1
//基本：0


int eat(int level) {
	if (eatLog[level][0] != 0 && X> eatLog[level][1]) {
		result += eatLog[level][0];
		X -= eatLog[level][1];
		return 0;
	}
	long long int start_result = result;
	long long int  start_eat = X;
	if (level == 0) {
		++result;
		if (--X == 0)return 1;
	}
	else {//パン
		if (--X == 0)return 1;		
		//レベル level-1 バーガー
		if (eat(level - 1))return 1;
		//パティ
		++result;
		if (--X == 0)return 1;
		//レベル level-1 バーガー
		if (eat(level - 1))return 1;
		//パン
		if (--X == 0)return 1;
	}
	eatLog[level][0] = result-start_result ;
	eatLog[level][1] = start_eat - X;
	return 0;
}


int main() {
	scanf("%d %lld", &N, &X);
	eat(N);
	printf("%lld", result);
	
}
