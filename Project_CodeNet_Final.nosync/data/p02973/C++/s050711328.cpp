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
#include <stack>
#include <map> 
#include <unordered_map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL unsigned long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N;
LL A[100000];

LL ans = 0;

void solve(){
	multiset<LL> arrays;
	arrays.insert(A[0]);
	for(int i=1;i<N;i++){
		auto iter = arrays.lower_bound(A[i]);
		if(iter==arrays.begin()) arrays.insert(A[i]);
		else{
			iter--;
			arrays.erase(iter);
			arrays.insert(A[i]);
		}
	}
	ans = arrays.size();
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];

    solve();

    cout << ans << endl;
    return 0;
}