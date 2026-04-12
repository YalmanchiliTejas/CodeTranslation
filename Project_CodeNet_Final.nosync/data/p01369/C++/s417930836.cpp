#include <bits/stdc++.h>
using namespace std;

string s;
string t = "yuiophjklnm";

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	while(1){
		cin >> s;
		if(s == "#") return 0;
		for(int i=0; i<s.size(); ++i){
			bool f = false;
			for(int j=0; j<t.size(); ++j)
				if(s[i] == t[j])
					f = true;
			if(f) s[i] = '0';
			else s[i] = '1';
		}
		int ans = 0;
		for(int i=1; i<s.size(); ++i)
			if(s[i] != s[i-1])
				++ans;
		cout << ans << "\n";
	}
}
