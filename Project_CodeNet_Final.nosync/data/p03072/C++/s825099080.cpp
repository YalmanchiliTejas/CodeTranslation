// Contest.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include"iostream"
#include"string"
#include"vector"
#include"algorithm"

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int>a(N);
	for (int i = 0; i < N; i++)cin >> a[i];

	int memo = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (memo <= a[i]) {
			ans++;
			memo = a[i];
		}
	}
	cout << ans << endl;
	return 0;
}


