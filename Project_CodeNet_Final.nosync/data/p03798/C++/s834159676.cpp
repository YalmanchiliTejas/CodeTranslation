#include <iostream>
#include<string>

using namespace std;

int N;
string s;

bool CHECK(string str) {

	for (int i = 0; i <= N - 1; i++) {
		//cout << s[i] << " " << str[i] << endl;
		if (s[i] == 'o' && str[i] == 'S') { if (str.substr((i - 1 + N) % N,1 ) == str.substr((i + 1) % N,1)) {} else { return false; } }
		else if (s[i] == 'o' && str[i] == 'W') { if (str.substr((i - 1 + N) % N,1) != str.substr((i + 1) % N,1)) {} else { return false; } }
		else if (s[i] == 'x' && str[i] == 'S') { if (str.substr((i - 1 + N) % N,1) != str.substr((i + 1) % N,1)) {} else { return false; } }
		else if (s[i] == 'x' && str[i] == 'W') { if (str.substr((i - 1 + N) % N,1) == str.substr((i + 1) % N,1)) {} else { return false; } }
	}
	return true;
}

string s1, s2, s3, s4;

string ANTI(string str) {
	if (str == "S") { return "W"; }
	return "S";
}

string EXPAND(string str) {

	string ret = str;

	for (int i = 2; i <= N - 1; i++) {
		if (s[i - 1] == 'o' && ret[i-1]=='S') { ret += ret.substr(i - 2, 1); }
		else if (s[i - 1] == 'o' && ret[i - 1] == 'W') { ret += ANTI(ret.substr(i - 2, 1)); }
		else if (s[i - 1] == 'x' && ret[i - 1] == 'S') { ret += ANTI(ret.substr(i - 2, 1)); }
		else if (s[i - 1] == 'x' && ret[i - 1] == 'W') { ret += ret.substr(i - 2, 1); }
	}

	return ret;
};

int main(void) {

	cin >> N;
	cin >> s;

	string ans;

	s1 = "SS";
	s1 = EXPAND(s1); //cout << "s1= "<< s1 << endl;	
	if (CHECK(s1)) { ans = s1; }

	s2 = "SW";
	s2 = EXPAND(s2); //cout << "s2= " << s2 << endl;
	if (CHECK(s2)) { ans = s2; }

	s3 = "WS";
	s3 = EXPAND(s3);// cout << "s3= " << s3 << endl;
	if (CHECK(s3)) { ans = s3; }

	s4 = "WW";
	s4 = EXPAND(s4); //cout << "s4= " << s4 << endl;
	if (CHECK(s4)) { ans = s4; }


	if (ans == "") { cout << -1 << endl; }
	else { cout << ans << endl; }



	//system("pause");
	return 0;
}