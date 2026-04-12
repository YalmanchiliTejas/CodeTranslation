#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> v;
	v.push_back("qwertasdfgzxcvb");
	v.push_back("yuiophjklnm");
	v.push_back("");
	string s;
	while(cin >> s,s!="#"){
		int idx = 2,cnt=0;
		for(int unsigned i = 0;i<s.size();i++){
			if(find(v[0].begin(),v[0].end(),s[i]) != v[0].end()){
				if(idx != 0)cnt++;
				idx=0;
			}
			if(find(v[1].begin(),v[1].end(),s[i]) != v[1].end()){
				if(idx != 1)cnt++;
				idx=1;
			}
		}
		cout << cnt-1 << endl;
	}
	return 0;
}