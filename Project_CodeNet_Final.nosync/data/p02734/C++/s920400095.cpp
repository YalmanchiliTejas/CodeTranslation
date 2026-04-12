#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>
#include <string>
#include <complex>
using namespace std;

#define INT_max 2147483647


typedef long long ll;
typedef long double ld;


char change(char x){
	if(x == '9') return '1';
	return x+1;
}


int main(){
	int mod = 998244353;
	int N,S;
	cin>>N>>S;
	vector<ll> num(S+1,0);
	num[0] = 1;
	ll ans = 0;
	for(int i = 0;i < N;i++){
		int t;
		cin>>t;
		for(int j = S;j >= t;j--){
			num[j] += num[j-t];
			num[j] %= mod;
		}
		num[0]++;//这个表示的是另一个起点
		ans += num[S];
		ans %= mod;
	}
	cout<<ans<<endl;
	return 0;
}