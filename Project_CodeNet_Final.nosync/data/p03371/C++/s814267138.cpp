#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>

using namespace std;

int X; //Aの枚数
int Y; //B
int Z1,Z2 = 0; //AB

int get_max(int *X, int *Y) {
	int max = 0;
	if (*X > *Y) {
		max = *X;
	}
	else {
		max = *Y;
	}
	return max;
}

int max_num_cost(int *X, int *Y, int *a, int *b) {
	int max = 0;
	if (*X > *Y) {
		max = *a;
	}
	else {
		max = *b;
	}
	return max;
}

int get_min(int *X, int *Y) {
	int min = 0;
	if (*X < *Y) {
		min = *X;
	}
	else {
		min = *Y;
	}
	return min;
}

int main() {
	int a, b, c = 0; //ピッツァの価格
	int ans = 0;

	cin >> a >> b >> c >> X >> Y;
	//ハーフを入れて買うのがお得な時(ABの値段の2倍がA,Bの和を超えないとき)
	if ((a + b) > c * 2) {
		
		int ans1, ans2 = 0;
		//全ての種類で組み合わせる場合
		int max_num,max_val=0; //A.Bで大きい方の枚数と価格
		max_num = get_max(&X, &Y); //大きい方の枚数
		max_val = max_num_cost(&X, &Y, &a, &b); //枚数が大きい方の値段

		Z1 = get_min(&X, &Y) * 2; //A,Bの少ない方の枚数をABで実現する⇒ABの枚数
		int zan = max_num - get_min(&X, &Y); //大きい方の残枚数
		ans1 = max_val * zan + c * Z1;

		//ABセットのみで完結する場合
		int Z2 = get_max(&X, &Y) * 2;//大きい方の枚数をABだけで完成させる⇒ABの枚数
		ans2 = Z2 * c;

		ans = get_min(&ans1,&ans2);
	}
	//ハーフを入れて買わない時
	else {
		ans = a * X + b * Y;
	}

	cout << ans << endl;
	return 0;
}