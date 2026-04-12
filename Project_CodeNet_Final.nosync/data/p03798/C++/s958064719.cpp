#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

inline char opp(char ch){
	return ch == 'S'?'W':'S';
}

inline bool check(string s, string ret){
	int n = s.size();
	if(ret[0] == 'S'){
		if(s[0] == 'o' && ret[1] != ret[n - 1])return false;
		if(s[0] == 'x' && ret[1] == ret[n - 1])return false;
	}else{
		if(s[0] == 'o' && ret[1] == ret[n - 1])return false;
		if(s[0] == 'x' && ret[1] != ret[n - 1])return false;
	}
	if(ret[n - 1] == 'S'){
		if(s[n - 1] == 'o' && ret[0] != ret[n - 2])return false;
		if(s[n - 1] == 'x' && ret[0] == ret[n - 2])return false;
	}else{
		if(s[n - 1] == 'o' && ret[0] == ret[n - 2])return false;
		if(s[n - 1] == 'x' && ret[0] != ret[n - 2])return false;
	}
	return true;
}

void process(string s, string t){
	string ret = t;
	int n = s.size();
	for(int i = 1; i + 1 < n; i++){
		if(ret[i] == 'S'){
			if(s[i] == 'o')ret += ret[i - 1];
			else ret += opp(ret[i - 1]);
		}else{
			if(s[i] == 'x')ret += ret[i - 1];
			else ret += opp(ret[i - 1]);
		}
	}
	if(!check(s, ret))return;
	cout<<ret<<'\n';
	exit(0);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	string s;
	cin>>s;
	process(s, "SS");
	process(s, "SW");
	process(s, "WS");
	process(s, "WW");
	cout<<-1<<'\n';

	return 0;
}