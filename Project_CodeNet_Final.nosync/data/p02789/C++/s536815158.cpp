#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vs = vector<string>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e9 + 7;
const int MAX_N = 2e5, MAX_M = 1e5, MAX_K = 1e9;

//qsortでの比較用の関数 cmp
//qsort(配列名,要素数,sizeof(要素型),cmp)
int cmp(const void *p, const void *q) {
	return *(int*)p - *(int*)q;
}

int n, m;
void solve() {
	if (n == m) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}	
int main() {
	cin >> n >> m;
	solve();
}
