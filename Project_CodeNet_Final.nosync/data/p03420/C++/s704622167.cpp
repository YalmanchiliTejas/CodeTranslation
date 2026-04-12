#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	for (int i = k + 1; i <= n; i++) {
		ans += (i - k)*(n / i);
		if (n%i >= k) ans += n%i - k + 1;
	}
  if(k==0) ans-=n;
	cout << ans << endl;
}