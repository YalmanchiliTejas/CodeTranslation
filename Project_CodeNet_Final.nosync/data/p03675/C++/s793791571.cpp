#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,x,n) for(int i=x;i<n;i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;
typedef pair<int, int> PI;
typedef vector<int> VI;
int a[200000];
int b[200000];
int main() {
	int n;
	cin >> n;
	rep(i, n) cin >> a[i];
	int cnt = 0;
	if (n % 2 == 0) {
		for (int i = n; i > 0; i -= 2) b[cnt++] = i;
		for (int i = 1; i < n; i += 2) b[cnt++] = i;
	}
	else {
		for (int i = n; i > 0; i -= 2) b[cnt++] = i;
		for (int i = 2; i < n; i += 2) b[cnt++] = i;
	}
	rep(i, n) cout << a[b[i] - 1] << " ";
	cout << endl;
}