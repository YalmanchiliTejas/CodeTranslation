#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<ll> a;
vector<vector<ll> > memo;

ll rec(int left, int right){
	if(left > right) return 0;
	if(memo[left][right] != -1) return memo[left][right];
	int turn = (n - (right - left)) % 2;
	if(turn == 1){
		return memo[left][right] = max(rec(left + 1, right) + a[left], rec(left, right - 1) + a[right]);
	}
	else{
		return memo[left][right] = min(rec(left + 1, right) - a[left], rec(left, right - 1) - a[right]);
	}
}

signed main(){
	scanf("%d", &n);
	a.resize(n);
	memo.resize(n, vector<ll> (n, -1));
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}
	cout << rec(0, n - 1) << endl;
}