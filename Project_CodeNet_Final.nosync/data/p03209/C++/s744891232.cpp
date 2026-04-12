#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

ll N, X, ans = 0, pos = 1;
ll p[55];//p[i] = レベルiバーガーに含まれるパティの数
ll t[55];//t[i] = レベルiバーガーの層の数

//p[]の初期化
void init(){
	p[0] = 1;
	t[0] = 1;
	for(int i = 1; i <= N; i ++){
		p[i] = 2 * p[i - 1] + 1;
		t[i] = 2 * t[i - 1] + 3;
	}
}
ll solve(ll level, ll layer){
	if(level == 0){
		if(layer > 0)return 1;
		return 0;
	}
	/*if(layer == 1)return 0;
	if(layer <= t[level - 1] + 1)return solve(level - 1, layer - 1);
	if(layer == t[level - 1] + 2)return p[level - 1] + 1;
	if(layer <= 2 * t[level - 1] + 2)return p[level] + 1 + solve(level - 1, layer - 2 - t[level - 1]);
	if(layer == 2 * t[level - 1] + 3)return 2 * p[level - 1] + 1;*/
	if(layer == 1)return 0;
	if(layer < t[level - 1] + 1)return solve(level - 1, layer - 1);
	if(layer == t[level - 1] + 1)return p[level - 1];
	if(layer == t[level - 1] + 2)return p[level - 1] + 1;
	if(layer < t[level - 1] + 2 + t[level - 1])return p[level - 1] + 1 + solve(level - 1, layer - 2 - t[level - 1]);
	if(layer == t[level - 1] + 2 + t[level - 1])return p[level - 1] + 1 + p[level - 1];
	if(layer == t[level - 1] + 3 + t[level - 1])return p[level - 1] + 1 + p[level - 1];
}
int main(){

	cin >> N >> X;
	init();
	cout << solve(N, X) << endl;
	
	return 0;
}