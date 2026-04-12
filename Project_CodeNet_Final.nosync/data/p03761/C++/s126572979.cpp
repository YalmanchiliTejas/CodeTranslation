#include <bits/stdc++.h>

#define mod 1000000007

#define rep(i, n) for(int i=0; i<n; ++i)

using namespace std;
typedef long long ll;
const long long INF = 1LL << 60;
 
int main(void){
	
	int n, ans[26];
	rep(i, 26)
		ans[i] = 100000;
	
	cin >> n;
	
	rep(i, n){
		int count[26] = {};
		string s;
		cin >> s;
		rep(j, s.length())
			rep(c, 26)
				if(s[j] == 'a' + c)
					count[c]++;	
		rep(k, 26)
			ans[k] = min(ans[k], count[k]);
	}
	
	rep(i, 26)
		rep(j, ans[i])
			cout << char('a' + i);
		
	return 0;
}