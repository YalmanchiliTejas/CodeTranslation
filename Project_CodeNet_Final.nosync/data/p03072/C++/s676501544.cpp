#include <bits/stdc++.h>
using namespace std;


// ABC124B - Great Ocean View
// https://atcoder.jp/contests/abc124/tasks/abc124_b
void ABC124B() {
	int N;
	cin >> N;

	vector<int> H(N);
	for (int i = 0; i < N; i++)
	{
		cin >> H[i];
	}

	int ans = 0;
	for  (int i = 0; i < N; i++)
	{
		bool can_see = true;
		for  (int j = 0; j < i; j++) //jはiよりも西側の山
		{
			//自分より西側の山の方が高いときは海が見えない
			if (H[i] < H[j]) {
				can_see = false;
				break;
			}
		}

		if (can_see) {
			ans++;
		}

	}

	cout << ans << endl;
}


int main() {
	ABC124B();

	return 0;
}