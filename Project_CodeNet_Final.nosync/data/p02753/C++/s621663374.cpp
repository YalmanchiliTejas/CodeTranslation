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
 
string S;
 
string ans = "No";
 
void solve(){
	if(S[0]!=S[1] || S[1]!=S[2]){
		ans = "Yes";
	}
}
 
int main(){
	cin >> S;
 
	solve();
 
	cout << ans << endl;
	return 0;
}