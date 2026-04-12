#include<bits/stdc++.h>
using namespace std;
using lint = long long;
lint N, l, r;
vector<lint> a;
vector<vector<lint> > memo;

lint rec(lint l, lint r){
	if(l > r) return 0;
	if(memo[l][r] != -1) return memo[l][r];
	if((N - (r - l + 1)) % 2 == 0) {
		if(rec(l + 1, r) + a[l] >= rec(l, r - 1) + a[r]){
			return memo[l][r] = rec(l + 1, r) + a[l]; l++;
		}
		else return memo[l][r] = rec(l, r - 1) + a[r]; r--;
	}
	else{
		if(rec(l + 1, r) - a[l] <= rec(l, r - 1) - a[r]){
			return memo[l][r] = rec(l + 1, r) - a[l]; l++;
		}
		else return memo[l][r] = rec(l, r - 1) - a[r]; r--;
	}
}

signed main(){
	cin >> N;
	a.resize(N);
	for(lint i = 0; i < N; i++) cin >> a[i];
	memo.resize(N, vector<lint> (N, -1));
	l = 0, r = N - 1;
	cout << rec(l, r) << endl;
}