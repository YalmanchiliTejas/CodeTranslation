#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n, m;
	while (cin >> n >> m){
		if (!n && !m)return 0;
		long long a[20001], ans = 0;
		for (int i = 0; i < n + m; i++)cin >> a[i]; sort(a, a + n + m);
		ans = a[0];
		for (int i = 1; i < n + m; i++)ans = max(ans, a[i] - a[i - 1]);
		cout << ans << endl;
	}
}