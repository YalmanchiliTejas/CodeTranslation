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

LL N;
LL A[100000];

LL ans = 0;

void solve(){
	sort(A,A+N);
	if(N%2==0){
		for(int i=N-1;i>=N/2 + 1;i--) ans += (2*A[i]);
		ans += A[N/2];
		for(int i=0;i<N/2-1;i++) ans -= (2*A[i]);
		ans -= A[N/2-1];
	}else{
		for(int i=N-1;i>=(N+1)/2;i--) ans += (2*A[i]);
		for(int i=0;i<=(N+1)/2-3;i++) ans -= (2*A[i]);
		ans -= (A[(N+1)/2-2] + A[(N+1)/2-1]);

		LL cand = 0;
		for(int i=N-1;i>=(N-1)/2 + 2;i--) cand += (2*A[i]);
		cand += (A[(N-1)/2+1] + A[(N-1)/2]);
		for(int i=0;i<=(N-1)/2-1;i++) cand -= (2*A[i]);
		ans = max(ans,cand);
	}
}
 
int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
 
    solve();

    cout << ans << endl;
    return 0;
}