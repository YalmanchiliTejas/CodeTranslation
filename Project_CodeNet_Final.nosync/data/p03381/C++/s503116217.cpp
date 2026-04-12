// Never Give Up!
#include <stdio.h>
#include <iostream>
#include <limits>
#include <cstdint>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <bitset>
#include <array>
#include <string.h>
#include <stack>
#include <queue>
#include <stdint.h>
#include <sstream>
#include <map>
#include <set>
#include <locale>
#define mem(x, y) memset(x, y, sizeof x);
#define __STDC_LIMIT_MACROS
#define fio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn = 2 * 1e5 + 10 , INF = 1e9;
int n , a[maxn] , ta[maxn];
map<int , int> mp;

int main(){     
      
	fio;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ta[i] = a[i];
	}
	sort(a + 1 , a + n + 1);
	for(int i = 1; i <= n; i++){
		if(i <= n / 2) mp[a[i]] = a[n/2 + 1];
		else mp[a[i]] = a[n/2];
	}


	for(int i = 1; i <= n; i++){
		cout << mp[ta[i]] << endl;
	}


    	return 0;
}