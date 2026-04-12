//g++ -std=c++14 test.cpp -o test.out

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
const int INF_INT = 2147483647-1e6;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,X;

LL ans = 0;

vector<LL> numof_max_patty(51,-1);//レベルLバーガーが含む最大のパティ数をnumof_max_patty[L]とおく

LL numof_max_patty_init(LL L){
	if(L==1){
		if(numof_max_patty[1]==-1) numof_max_patty[1] = 3LL;
		return numof_max_patty[1];
	}
	if(numof_max_patty[L]==-1){
		numof_max_patty[L] = 2*numof_max_patty_init(L-1) + 1LL;
		return numof_max_patty[L];
	}
	return numof_max_patty[L];
}

LL get_numof_patty(LL L,LL x){//レベルLバーガーを下からx枚目まで見たときのパティの数を返す
	if(x<=1) return 0LL;
	if(L==1){
		//このとき1<=x<=5
		if(x>=5) return numof_max_patty[1];
		else return x-1LL;
	}else{
		LL numof_layer = (1LL<<(L+2)) - 3LL;//レベルLのハンバーガーの層数
		if(numof_layer/2 + 1 > x){
			return get_numof_patty(L-1,x-1);
		}
		if(numof_layer/2 + 1 == x){
			return numof_max_patty[L-1] + 1LL;
		}
		if(numof_layer/2 + 1 < x){
			LL l_1 = (1LL<<(L+1)) - 3LL;//レベルL-1のハンバーガーの層数
			return numof_max_patty[L-1] + 1LL + get_numof_patty(L-1,x-2-l_1);
		}
	}
	return -INF;
}

void solve(){
	numof_max_patty_init(50);
	ans = get_numof_patty(N,X);
}
 
int main(){
    cin >> N >> X;
 
    solve();

    cout << ans << endl;
    return 0;
}