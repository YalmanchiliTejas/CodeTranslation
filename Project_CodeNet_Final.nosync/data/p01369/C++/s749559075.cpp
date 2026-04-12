#include <bits/stdc++.h>
using namespace std;

int main(void){
	string s;
	bool mode = false;
	int cnt = 0;
	set<char> st = {'y','u','i','o','p','h','j','k','l','n','m'};
	while(true){
		cin >> s;
		if(s == "#") break;
		for(int i = 0; i < s.size(); ++i){
			if(st.find(s[i]) != st.end()){
				if(mode){
					cnt++;
					mode = !mode;
				}
			}else{
				if(!mode){
					cnt++;
					mode = !mode;
				}
			}
			if(i == 0) cnt = 0;
		}
		cout << cnt << endl;
	}
	return 0;
}
