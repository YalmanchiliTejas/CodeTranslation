#include <bits/stdc++.h>
using namespace std;

string qwe("yuiophjklnm");

int main() {
	string s;
	while(cin >> s && s != "#"){
		int ans = 0, t = 0;
		for(int i = 0; i < qwe.size(); ++i){
			if(s[0] == qwe[i]){
				t = 1;
				break;
			}
		}
		for(int i = 1; i < s.size(); ++i){
			bool flag = false;
			for(int j = 0; j < qwe.size(); ++j){
				if(s[i] == qwe[j]){
					if(!t){
						ans++;
						t ^= 1;
					}
					flag = true;
					break;
				}
			}
			if(t && !flag){
				ans++;
				t = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}