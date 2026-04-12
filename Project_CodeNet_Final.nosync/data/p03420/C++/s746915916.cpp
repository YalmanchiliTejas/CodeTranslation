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
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,K;

LL ans = 0;

void solve(){
	//a = pb + r (0<=r<=b-1)とおく
	//bを固定して考える
	for(int b=K+1;b<=N;b++){
		//cout << "b=" << b << endl;
		//cout << ((b-K)*(N/b) + max(0LL,N%b-K+1)) << endl;
		ans += (b-K)*(N/b) + max(0LL,N%b-K+1);
	}
	if(K==0) ans -= N;
}
 
int main(){
    cin >> N >> K;
 
    solve();

	cout << ans << endl;
    return 0;
}