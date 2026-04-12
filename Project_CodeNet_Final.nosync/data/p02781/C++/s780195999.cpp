#include "bits/stdc++.h"

using namespace std;

long long dp[105][105];
bool memoize[105][105];

int arr[105];

string s;
int k;

long long solve(int pos, int one = 0, bool flag = 1, bool take = 0) {  
      if (pos < 0) return one == k;  
      long long &ret = dp[pos][one];  
      bool &mem = memoize[pos][one];  
      if (!flag && take && mem) return ret;  
      int loop = 9;  
      if (flag) {
	loop = arr[pos];  
	}	
      long long sum = 0;  
      for (int i = 0; i <= loop; i++) {  
            if (!take && i == 0) sum += solve(pos-1, 0, 0, 0);  
            else sum += solve(pos-1, one + (i > 0), flag & i == arr[pos], 1);  
      }  
      if (!flag && take) {
		mem = 1, ret = sum;  
      }
	return sum;  
} 

long long digitDp() {
	int len = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		arr[len++] = s[i] - '0';
	}
	return solve(len - 1);
}

signed main() {
	cin >> s >> k;
	cout << digitDp() << endl;
}