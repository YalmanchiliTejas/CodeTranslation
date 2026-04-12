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
typedef pair<ll,ll> P;
#define REP(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back // vectorに要素追加
#define INF (ll)1e18
// int 
// // 各桁の和を計算する関数
// int findSumOfDigits(int n) {
//   int amari = 0;
//   int keta = 0;
//   while (n > 0) { // n が 0 になるまで
//     amari += n % 2;
//     if (keta%2==0)
//     n /= 10;
//   }
//   return sum;
// }
 
 

int main() {
	// 入力
	ll X, Y, Z;
	cin >>X>>Y>>Z;
 
	// 解法
	ll count = 0;
	ll wide = 0;
	while (true){
		if (count==0) wide = Y + 2*Z;
		else wide += Y+Z;
		if (wide<=X)count++;
		else break;
	}
	
	//出力
	cout << count << endl;
}
