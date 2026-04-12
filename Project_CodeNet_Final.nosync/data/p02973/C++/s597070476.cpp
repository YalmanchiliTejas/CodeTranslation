//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/abc134/tasks/abc134_e

//multisetの注意点：
//ある値iをmultisetから削除したい時、erase(i)をすると
//multisetにiが複数入っている時これが全部削除対象になる
//一個だけ削除したい時は
//削除したい要素のイテレータをeraseの引数にしておく必要がある

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N;
LL A[100000];
 
LL ans = 0;

void solve(){
	//数をグループに分類、グループの数を回答とする
	multiset<LL> group_max;//各グループに格納されている数のうち最大値
	group_max.insert(A[0]);
	for(int i=1;i<N;i++){
		auto iter = group_max.lower_bound(A[i]);
		if(iter==group_max.begin()){
			group_max.insert(A[i]);
			continue;
		}
		iter--;
		if(*iter<A[i]){
			group_max.erase(iter);
			group_max.insert(A[i]);
		}else{
			group_max.insert(A[i]);
		}
	}
	ans = (LL)group_max.size();
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
 
    solve();
 
    cout << ans << endl;
    return 0;
}