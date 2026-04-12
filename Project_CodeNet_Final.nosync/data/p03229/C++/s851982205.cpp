#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n, A[100000];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	sort(A, A + n);
	long long ans = 0, ansa = 0, ansb = 0;
	if (n % 2 == 0) {
		for (int i = 0; i < n / 2; i++) ans -= A[i] * 2;
		for (int i = n / 2; i < n; i++) ans += A[i] * 2;
		ans = ans - A[n / 2] + A[n / 2 - 1];
	}
	else {
		for (int i = 0; i < (n-1) / 2; i++) ansa -= A[i] * 2;
		for (int i = (n-1) / 2; i < n; i++) ansa += A[i] * 2;
		ansa = ansa - A[(n-1) / 2] - A[(n+1) / 2 ];
		for (int i = 0; i < (n + 1) / 2; i++) ansb -= A[i] * 2;
		for (int i = (n + 1) / 2; i < n; i++) ansb += A[i] * 2;
		ansb = ansb + A[(n - 3) / 2] + A[(n - 1) / 2 ];
		ans = max(ansa, ansb);
	}
	cout << ans;
}
