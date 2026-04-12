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
#include <string.h>

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
ll len_t(ll n){
	return pow(2,n+2)-3;
}

ll pn[51];

ll tn[51];

ll dfs(ll n, ll x){
	// printf("dfs(%lld, %lld) len_t=%lld\n", n, x, len_t(n));
	if (n==0 & x==1){
		// printf("return 1\n");
		// dp[0][1] = 1;
		return 1;
	}
	else if (x<=1){
		// dp[0][0] = 0;
		return 0;
		// return dp[0][0];
	}
	else if (x>=len_t(n)-1){
		// cout << "return " << pow(2,n+1)-1 << endl;
		// printf("return %lld \n", pow(2,n+1)-1);
		// dp[n][x] = pow(2,n+1)-1;
		return pn[n];
	}
	// else if (x=len_t(n-1)+2){
	// 	printf("dfs(%lld, %lld) + 1\n", n-1, len_t(n-1));
		
	// 	return dfs(n-1, len_t(n-1)) + 1;
	// }
	else if (x>=len_t(n-1)+2){
		// printf("dfs(%lld, %lld) + ", n-1, len_t(n-1));
		// printf("dfs(%lld, %lld) + 1\n", n-1, x - len_t(n-1) - 2);
		return pn[n-1] + dfs(n-1, x - len_t(n-1) - 2) + 1;
		// return dp[n][x];
	}
	else{
		// dp[n][x] = dfs(n-1, x-1);
		return dfs(n-1, x-1);
	}
}
 

int main() {
	// 入力
	ll N, X;
	cin >> N >> X;
	
	// 解法
	REP(i,51){
		pn[i] = pow(2,i+1)-1;
	}
	
	REP(i,51){
		tn[i] = len_t(i);
	}
	// memset(dp, -1, sizeof(dp));
	ll ans = dfs(N,X);
	cout << ans << endl;
	
}
