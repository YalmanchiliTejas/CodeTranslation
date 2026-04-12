#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int MAXN = 100005;
const int mod = 998244353;

int main(){
	int n, k;
	cin >> n >> k;
	if(k == 0){
		cout << 1ll * n * n << endl;
		return 0;
	}
	lint ret = 0;
	for(int i=1; i<=n; i++){
		int mok = n / i;
		ret += mok * max(0, i - k);
		ret += max(n % i - k + 1, 0);
	}
	cout << ret << endl;
}
