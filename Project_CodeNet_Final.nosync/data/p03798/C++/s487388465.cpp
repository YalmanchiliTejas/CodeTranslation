#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
string S;

string sw = "SW";
map<pair<char,string>, char> mp;

int main() {
	cin >> N >> S;
	// s[0]が'S'か'W'かと, S[1], S[N-1]が'S'か'W'かを決めたらあとは一意に定まる
	// 定まったS[N-1]が本来あるべきS[N-1]か確かめればいい
	vector<pair<char, string>>  cs;
	cs.push_back(make_pair('S', "S"));
	cs.push_back(make_pair('W', "S"));
	cs.push_back(make_pair('S', "W"));
	cs.push_back(make_pair('W', "W"));

	mp[make_pair('o',"SS")] = 'S';
	mp[make_pair('o',"WS")] = 'W';
	mp[make_pair('o',"SW")] = 'W';
	mp[make_pair('o',"WW")] = 'S';

	mp[make_pair('x',"SS")] = 'W';
	mp[make_pair('x',"WS")] = 'S';
	mp[make_pair('x',"SW")] = 'S';
	mp[make_pair('x',"WW")] = 'W';

	for(int i=1;i<=N;i++) {
		for(int j=0;j<cs.size();j++) {
			if(i == 1) {
				string tmp = "";
				tmp += cs[j].first;
				tmp += cs[j].second[i-1];
				cs[j].second += mp[make_pair(S[i-1], tmp)];
			} else {
				string tmp = "";
				tmp += cs[j].second[i-2];
			  	tmp += cs[j].second[i-1];
				cs[j].second += mp[make_pair(S[i-1], tmp)];
			}
		}
	}
	string ans = "-1";
	for(int i=0;i<cs.size();i++) {
		if(cs[i].second[0] == cs[i].second[N] and cs[i].first == cs[i].second[N-1]) {
			(cs[i].second).pop_back();
			ans = cs[i].second;
		}
	}
	cout << ans << endl;
}