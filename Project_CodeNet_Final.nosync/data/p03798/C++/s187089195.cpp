#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
string S;

map<pair<char,string>, char> mp;

int main() {
	cin >> N >> S;
	S += S[0];
	// s[0]が'S'か'W'かと, S[1], S[N-1]が'S'か'W'かを決めたらあとは一意に定まる
	// 定まったS[N-1]が本来あるべきS[N-1]か確かめればいい
	vector<string>  cs;
	cs.push_back("SS");
	cs.push_back("SW");
	cs.push_back("WS");
	cs.push_back("WW");

	mp[make_pair('o',"SS")] = 'S';
	mp[make_pair('o',"WS")] = 'W';
	mp[make_pair('o',"SW")] = 'W';
	mp[make_pair('o',"WW")] = 'S';

	mp[make_pair('x',"SS")] = 'W';
	mp[make_pair('x',"WS")] = 'S';
	mp[make_pair('x',"SW")] = 'S';
	mp[make_pair('x',"WW")] = 'W';

	for(int i=2;i<=N+1;i++) {
		for(int j=0;j<cs.size();j++) {
			string tmp = "";
			tmp += cs[j][i-2];
			tmp += cs[j][i-1];
			cs[j] += mp[make_pair(S[i-1], tmp)];
		}
	}
	string ans = "-1";
	for(int i=0;i<cs.size();i++) {
		if(cs[i][0] == cs[i][N] and cs[i][1] == cs[i][N+1]) {
			cs[i].pop_back();
			cs[i].pop_back();
			ans = cs[i];
		}
	}
	cout << ans << endl;
}