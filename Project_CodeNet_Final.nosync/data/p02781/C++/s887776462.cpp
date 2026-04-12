#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
string s;
int k, ans, sz, t;
int main(){
	cin >> s >> k;
	sz = s.size();
	for(; k; k--){
		for(; s[t] == '0'; t++, sz--);
		if(sz < k) break;
		if(k == 3) ans += (sz - 1) * (sz - 2) * (sz - 3) / 6 * 9 * 9 * 9 + (s[t] - '1') * (sz - 1) * (sz - 2) / 2 * 9 * 9;
		else if(k == 2) ans += (sz - 1) * (sz - 2) / 2 * 9 * 9 + (s[t] - '1') * (sz - 1) * 9;
		else ans += (sz - 1) * 9 + (s[t] - '0');
		t++; sz--;
	}
	printf("%d\n",ans);
}