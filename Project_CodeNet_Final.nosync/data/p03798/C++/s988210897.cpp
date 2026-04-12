#include<iostream>
#include<string>

using namespace std;

int n;
string s, t[2] = {"S", "W"};

string solve(){
	for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++){
		string res = t[i] + t[j];
		for(int k = 1; k < n - 1; k++){
			if(res[k] == 'S' && s[k] == 'o' || res[k] == 'W' && s[k] == 'x') res += res[k - 1];
			else res += (res[k - 1] == 'S' ? 'W' : 'S');
		}
		if(res[0] == 'S' && s[0] == 'o' || res[0] == 'W' && s[0] == 'x'){ if(res[1] != res[n - 1]) continue; }
		else{ if(res[1] == res[n - 1]) continue; }
		if(res[n - 1] == 'S' && s[n - 1] == 'o' || res[n - 1] == 'W' && s[n - 1] == 'x'){ if(res[0] != res[n - 2]) continue; }
		else{ if(res[0] == res[n - 2]) continue; }
		return res;
	}
	return "-1";
}

int main(){
	cin >> n >> s;
	cout << solve() << endl;
	return 0;
}