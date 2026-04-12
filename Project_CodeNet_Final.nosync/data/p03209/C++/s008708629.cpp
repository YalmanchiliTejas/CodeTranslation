#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint rec(lint N, lint x){
	if(N == 0) return 1;
	if(x == 0) return 0;
	if(x == 1) return 0;
  lint len = (1LL << (N + 1)) - 3;
	lint num = (1LL << N) - 1;
	if(x <= 1 + len) return rec(N - 1, x - 1);
	if(x == 2 + len) return num + 1;
	if(x > 2 + len && x <= 2 + 2 * len) return num + 1 + rec(N - 1, x - len - 2);
	if(x == 3 + 2 * len) return 2 * num + 1;
}

signed main(){
	lint N, X; cin >> N >> X;
	cout << rec(N, X) << endl;
}
