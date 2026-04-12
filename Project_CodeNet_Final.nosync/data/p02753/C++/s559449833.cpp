#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	string s;
	cin >> s;
	set<char> st;
	for(int i=0;i<3;i++) {
		st.insert(s[i]);
	}
	if(st.size() != 1) cout << "Yes" << endl;
	else cout << "No" << endl;
}