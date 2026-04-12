#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;

char p[128]={};
ll f() {
	stack<char> st;
	string r = "";
	for(auto c: s)
		if(isdigit(c)) r += c;
		else {
			while(st.size()&&p[st.top()]>=p[c]) {
				r += st.top(); st.pop();
			}
			st.push(c);
		}
	while(st.size()) { r += st.top(); st.pop(); }
	stack<ll> a;
	for(auto c: r)
		if(isdigit(c)) a.push(c-'0');
		else {
			ll x = a.top(); a.pop();
			ll y = a.top(); a.pop();
			a.push(c == '*' ? x * y : x + y);
		}
	return a.top();
}

int main() {
	ll ans;
	cin >> s >> ans;
	p['+']=1; p['*']=2; ll a1 = f();
	p['+']=1; p['*']=1; ll a2 = f();
	if(a1==ans&&a2==ans)puts("U");
	else if(a1==ans) puts("M");
	else puts(a2 == ans ? "L" : "I");
	return 0;
}