#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	cout.precision(13);
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n,q;
	cin >> n >> q;
	bool one[n] = {};
	int cur = 0;
	one[1] = 1;
	while(q--){
		int a,b;
		cin >> a >> b;
		--a;--b;
		if(a == cur)cur = b;
		else if(b == cur)cur = a;

		swap(one[a], one[b]);
		if(cur - 1 >= 0)one[cur-1] = 1;
		if(cur + 1 < n)one[cur+1] = 1;
	}
	one[cur] = 1;
	int ans = accumulate(one,one+n,0);
	cout << ans << '\n';
}
