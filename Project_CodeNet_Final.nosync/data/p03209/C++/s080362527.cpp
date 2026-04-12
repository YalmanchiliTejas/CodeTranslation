#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;

static long long INF = (1LL<<62);

LL P[52] = {0}; //T[i]はレベルiハンバーガのパティの枚数
LL B[52] = {0}; //T[i]はレベルiハンバーガのパンの枚数
LL T[52] = {0}; //T[i]はレベルiハンバーガのパティ+パンの枚数

void init(){
	P[0] = 1;
	B[0] = 0;
	T[0] = 1;

	LL b = 2;
	for(int i=1; i<=50; i++){
		b *= 2;
		P[i] = b - 1;
		B[i] = b - 2;
		T[i] = P[i] + B[i];
	}
}

//level n ハンバーガの下x層に含まれるパティの枚数を返す
LL f(int n, LL x){
	if(x <= 0 || n < 0){
		return 0;
	}
	if(x == 1){
		if(n == 0){
			return 1;
		}
		else{
			return 0;
		}
	}
	LL t = T[n] / 2;
	if(x <= t){
		return f(n-1, x-1);
	}
	else if(x == t+1){
		return P[n-1] + 1;
	}
	else{
		return P[n-1] + 1 +  f(n-1, x - (t+1));
	}
}

LL N, X;
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> X;

	init();
	LL ans = f(N, X);
	printf("%lld\n", ans);
	return 0;
}