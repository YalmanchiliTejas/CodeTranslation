/*
オーダー
10**6	余裕を持って間に合う	
10**7	おそらく間に合う	余裕を持って間に合う
10**8	非常にシンプルな処理でない限り厳しい	おそらく間に合う
10**9		非常にシンプルな処理でない限り厳しい
logn	:OK
n		:10^7
nlogn	:10^6
n**2	:10^4
n**3	:300
2**n	:20
n!		:10



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
const ll MAX_N = 1e5;
ll N;
ll h[MAX_N];
ll dp[MAX_N+1]; // メモ化テーブル
 
// i番目以降の品物から重さの総和がj以下になるように選ぶ
void rec(ll i){
	if (i==0) dp[i] = 0;
	else if (i==1) dp[i] = abs(h[1]-h[0]);
	else dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
	return;
}


vector<ll> a;

// 二分探索 drken
// https://qiita.com/drken/items/97e37dd6143e33a64c8c
// index が条件を満たすかどうか
bool isOK(ll index, ll key) {
    if (a[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key) {
    int left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int right = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while (right - left > 1) {
        int mid = left + (right - left) / 2;

        if (isOK(mid, key)) right = mid;
        else left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return right;
}



int main() {
	// 入力
	ll N;
	cin >> N;
	ll A[N];
	for (ll i = 0; i < N; ++i) cin >> A[i];
 
	
	// 解法
	REP(i,N){
		ll tmp = binary_search(A[i]);
		// cout << tmp << endl;
		if (tmp==0){
			// a.pb(A[i]);
			a.insert(a.begin(), A[i]);
		}
		else{
			a[tmp-1] = A[i];
		}
		// printf("%lld : ", A[i]);
		// REP(i, a.size()) printf("%lld ", a[i]);
		// printf("\n");
	}
	cout<< a.size()<<endl;
}
