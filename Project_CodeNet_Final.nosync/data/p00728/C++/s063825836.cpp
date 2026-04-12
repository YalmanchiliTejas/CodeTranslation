#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>

#define BIT(a) (1 << (a))

using namespace std;

long long MOD = 1000000007;


long long mod_pow(long long x, long long n){
    long long res = 1;
    for(int i = 0;i < 60; i++){
        if(n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

vector<int> v[30];
int ans[30];
int main(void){
	int N;
	int cnt = 0;
	while (1){
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++){
			int x;
			cin >> x;
			v[cnt].push_back(x);
		}
		cnt++;
	}
	for (int i = 0; i < cnt; i++){
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j < v[i].size(); j++){
			if (j == 0 || j == v[i].size()-1) continue;
			ans[i] += v[i][j];
		}
		ans[i] /= v[i].size() - 2;
	}

	for (int i = 0; i < cnt; i++){
		cout << ans[i] << endl;
	}
	return 0;
}


