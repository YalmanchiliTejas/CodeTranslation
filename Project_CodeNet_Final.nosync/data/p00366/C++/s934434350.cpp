#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int n;
int t[100005];
int a[10005];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0;i < n;i++){
		cin >> t[i];
	}

	sort(t,t+n);
	
	int tmp = n;
	for (int i = t[n-1];i > 0;i--){
		if(t[n-1]%i == 0) tmp = i;
		a[i] = tmp;
	}

	int ans = 0;

	for (int i = 0;i < n;i++){
		ans += a[t[i]] - t[i];
	}

	cout << ans << endl;

	return 0;

}

