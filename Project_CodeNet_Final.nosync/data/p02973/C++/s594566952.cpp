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

int A[100010];
int num[100010];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		//A[i] = 0;
		num[i] = -1;
	}
	int ans = 0;
	for (int i = N - 1; i >= 0; i--) {
		int ok = ans;
		int ng = -1;
		while (abs(ok - ng) > 1) {
			int mid = (ok + ng) / 2;
			if (A[i] < num[mid]) ok= mid;
			else ng = mid;
		}
		//cout << ok << endl;
		num[ok] = A[i];
		ans = max(ans, ok + 1);
	}
	cout << ans << endl;
}
