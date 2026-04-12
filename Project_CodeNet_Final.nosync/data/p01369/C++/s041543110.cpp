#include<bits/stdc++.h>
#define rep(i,n)for(ll i=0;i<n;i++)
using namespace std;
typedef long long ll;

int main() {
	string r = "yuiophjklmn";
	string s;
	while (cin >> s, s != "#") {
		int cnt = 0;
		bool right = false;
		if ((int)r.find(s[0]) >= 0)right = true;
		for (int i = 1; i < s.size(); i++) {
			bool b = (int)r.find(s[i]) >= 0;
			cnt += b^right;
			right = b;
		}
		printf("%d\n", cnt);
	}
}