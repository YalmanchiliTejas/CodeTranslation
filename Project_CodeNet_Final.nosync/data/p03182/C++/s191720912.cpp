#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;
typedef pair<P, long long int> P2;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

int const TREE_SIZE = 1 << 20;
long long int seg_tree[TREE_SIZE] = {};
long long int c_diff[TREE_SIZE] = {}; // 子との差

long long int find(int a, int b, int index, long long int diff, int l, int r){
	
	// [a, b) の最大値を求める
	
	seg_tree[index] += diff;
	c_diff[index] += diff;
	
	if(r <= a || b <= l){
		return -INF;
	}
	if(a <= l && r <= b){
		return seg_tree[index];
	}
	
	long long int ret = -INF;
	ret = max(ret, find(a, b, index * 2, c_diff[index], l, (l + r) / 2));
	ret = max(ret, find(a, b, index * 2 + 1, c_diff[index], (l + r) / 2, r));
	c_diff[index] = 0;
	return ret;
}

long long int add(int a, int b, int index, long long int num, long long int diff, int l, int r){
	
	// [a, b) に num を足す
	
	seg_tree[index] += diff;
	c_diff[index] += diff;
	
	if(r <= a || b <= l){
		return seg_tree[index];
	}
	if(a <= l && r <= b){
		seg_tree[index] += num;
		c_diff[index] += num;
		return seg_tree[index];
	}
	
	long long int ret = -INF;
	ret = max(ret, add(a, b, index * 2, num, c_diff[index], l, (l + r) / 2));
	ret = max(ret, add(a, b, index * 2 + 1, num, c_diff[index], (l + r) / 2, r));
	c_diff[index] = 0;
	return seg_tree[index] = ret;
}

int main(){
	
	int N, M;
	cin >> N >> M;
	
	long long int S = 0;
	
	vector<P2> v;
	P2 p = P2(P(INF, INF),0);
	v.push_back(p);
	
	for(int i = 0; i < M; i++){
		cin >> p.first.second >> p.first.first >> p.second;
		p.first.first += 1;
		p.first.second += 1;
		v.push_back(p);
		S += p.second;
	}
	
	sort(v.begin(), v.end());
	
	add(1, 2, 1, S, 0, 0, TREE_SIZE / 2);
	
	int pos = 0;
	
	for(int i = 2; i <= N + 2; i++){
		while(v[pos].first.first < i){
			add(1, v[pos].first.second, 1, -v[pos].second, 0, 0, TREE_SIZE / 2);
			pos += 1;
		}
		S = find(1, i, 1, 0, 0, TREE_SIZE / 2);
		add(i, i + 1, 1, S, 0, 0, TREE_SIZE / 2);
	}
	
	cout << S << endl;
	
	return 0;
}
