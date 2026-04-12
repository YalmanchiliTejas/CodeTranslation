#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n-1); i >= 0; i--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define repitr(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	string s;
	cin >> s;
	set<char> st;
	rep(i, 3){
		st.insert(s[i]);
	}
	if(st.size() == 1) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}