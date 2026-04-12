/*
for (int i = 0; i < N; ++i){}

// 各桁の和を計算する関数
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

sort(a, a + N, greater<int>());  // a[0:N] を大きい順にソート

int num[110] = {0};  // バケット
for (int i = 0; i < N; ++i) {
    num[d[i]]++;  // d[i] が 1 個増える
}

map<string, int> mp; // 連想配列 map<キー型, 値型> オブジェクト名
for (int i = 0; i < N; ++i) {
    auto itr = mp.find(s[i]);        // s[i] が設定されているか？
    if(itr != mp.end() ) {
         mp[s[i]] += 1;
    }
    else {
         mp[s[i]] += 1 ;
    }
}
stack<int> s;	//intをデータとするスタックを用意
s.push(1);		//{} -> {1}
printf("%d\n", s.top());	// 3
s.pop();

queue<int> que;	//intをデータとするキューを用意
que.push(1);		//{} -> {1}
printf("%d\n", que.front());	// 1
que.pop();
*/
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

// #define for(i,a,b) for (int i=(a);i<(b);++i)
typedef long long ll;
typedef pair<int,int> point;
#define rep(i,n) for(i,0,n)
 
int main() {
	// 入力
	int H, W;
	cin >> H >> W;
	char a[H+1][W+1];
	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			cin >> a[i][j];
		}
	}	
	
	// 解法


	// for (int i = 0; i < H; ++i){
	// 	for (int j = 0; j < W; ++j){
	// 		cout << a[i][j];
	// 	}
	// 	cout << endl;
	// }
	
	char b[H+1][W+1];
	for (int j = 0; j < W; ++j){
		bool onlyW = true;
		for (int i = 0; i < H; ++i){
			if (a[i][j]=='#'){
				onlyW = false;
				break;
			}
		}
		if (onlyW){
			for (int i = 0; i < H; ++i) b[i][j] = '+';
		}
		else{
			for (int i = 0; i < H; ++i) b[i][j] = a[i][j];
		}
	}
	
	for (int i = 0; i < H; ++i){
		bool onlyW = true;
		for (int j = 0; j < W; ++j){
			if (a[i][j]=='#'){
				onlyW = false;
				break;
			}
		}
		if (onlyW){
			for (int j = 0; j < W; ++j) b[i][j] = '-';
		}
		else{
			for (int j = 0; j < W; ++j) b[i][j] = b[i][j];
		}
	}
	

	for (int i = 0; i < H; ++i){
		if (b[i][0]!='-'){
			for (int j = 0; j < W; ++j){
				if (b[i][j]!='+') cout << b[i][j];
			}
			cout << endl;
		}
	}
}
 
