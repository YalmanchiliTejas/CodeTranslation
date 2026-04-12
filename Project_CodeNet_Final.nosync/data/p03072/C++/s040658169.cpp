#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n;
	cin >> n;

	int ans = 0;
	int cur_H = 0;
	rep(i, n){
		int a;
		cin >> a;
		cur_H = max(cur_H, a);
		if(a == cur_H) ans++;
	}
	cout << ans << endl;
}