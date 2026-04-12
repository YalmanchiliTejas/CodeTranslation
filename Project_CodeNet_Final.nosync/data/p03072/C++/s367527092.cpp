#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int main()
{
	int N;
	int H[21];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
	int ans = 0;
	for (int i = 0; i < N; i++) {
		bool ok = true;
		for (int j = 0; j < i; j++) {
			if (H[i] < H[j]) {
				ok = false;
				break;
			}
		}
		if (ok) ans++;
	}
	cout << ans << endl;
}
