#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; string s; cin >> n >> s;
	if(count(s.begin(), s.end(), 'o') == n) cout << string(n, 'S') << endl;
	else if(count(s.begin(), s.end(), 'o') == 0) cout << string(n, 'W') << endl;
	else {
		int i = 0, j = n - 1;
		while(s[i] == s[0]) i++;
		while(s[j] == s[0]) j--;
		auto build = [&](int l, int r, char inr0, char inr1, char inl0, char inl1, bool &ok){
			string nv;
			for(int i = l; i <= r; i++){
				char now;
				if(s[i] == 'x'){
					if(inl1 == 'S'){
						if(inl0 == 'S') now = 'W';
						else now = 'S';
					} else {
						now = inl0;
					}
				} else if(s[i] == 'o'){
					if(inl1 == 'S'){
						now = inl0;
					} else {
						if(inl0 == 'S') now = 'W';
						else now = 'S';	
					}
				}
				inl0 = inl1;
				inl1 = now;
				nv.push_back(inl0);
			}
			ok = inl0 == inr0 && inl1 == inr1;
			return nv;
		};
		auto fx = [&](char c){
			if(s[0] == 'o') return c;
			if(c == 'W') return 'S';
			return 'W';
		};
		int len = i + n - j - 1;
		{
			string opt(len + 2, fx('S'));
			bool good;
			string opt2 = build(i, j, opt[0], opt[1], opt[len], opt[len + 1], good);
			if(good){
				cout <<  opt.substr(n - j, i) + opt2 + opt.substr(1, n - j - 1) << endl;
				return 0;
			}
		}
		{
			string opt(len + 2, fx('S'));
			opt[0] = fx('S');
			opt[1] = fx('W');
			for(int i = 2; i < len + 2; i++) opt[i] = opt[i - 2] == opt[i - 1] ? fx('S') : fx('W');
			bool good;
			string opt2 = build(i, j, opt[0], opt[1], opt[len], opt[len + 1], good);
			if(good){
				cout <<  opt.substr(n - j, i) + opt2 + opt.substr(1, n - j - 1) << endl;
				return 0;
			}
		}
		{
			string opt(len + 2, fx('S'));
			opt[0] = fx('W');
			opt[1] = fx('S');
			for(int i = 2; i < len + 2; i++) opt[i] = opt[i - 2] == opt[i - 1] ? fx('S') : fx('W');
			bool good;
			string opt2 = build(i, j, opt[0], opt[1], opt[len], opt[len + 1], good);
			if(good){
				cout <<  opt.substr(n - j, i) + opt2 + opt.substr(1, n - j - 1) << endl;
				return 0;
			}
		}
		{
			string opt(len + 2, fx('S'));
			opt[0] = fx('W');
			opt[1] = fx('W');
			for(int i = 2; i < len + 2; i++) opt[i] = opt[i - 2] == opt[i - 1] ? fx('S') : fx('W');
			bool good;
			string opt2 = build(i, j, opt[0], opt[1], opt[len], opt[len + 1], good);
			if(good){
				cout <<  opt.substr(n - j, i) + opt2 + opt.substr(1, n - j - 1) << endl;
				return 0;
			}
		}
		cout << -1 << endl;
	}
	return 0;
}
