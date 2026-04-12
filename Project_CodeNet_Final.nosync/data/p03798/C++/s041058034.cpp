#include "bits/stdc++.h"

using namespace std;

//using Matrix = vector< vector<int> >;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9 + 10;
//const ll INF = 1e18 + 10LL;
int dx[5] = {0, 0, 1, -1, 0}, dy[5] = {1, -1, 0, 0, 0};
const double EPS = 1e-10;
bool cmp(P a, P b) { return a.second < b.second; } //End sort (Interval scheduling problem)
ll MOD = 1e9 + 7;

int n;
string s;

bool can;

string gen(string str) {

	for (int i = 2; i < n; i++) {
		if (str[i - 1] == 'S' && s[i - 1] == 'o') str += str[i - 2];
		else if (str[i - 1] == 'S' && s[i - 1] == 'x') {
			if (str[i - 2] == 'S') str += 'W';
			else str += 'S';
		}
		else if (str[i - 1] == 'W' && s[i - 1] == 'o') {
			if (str[i - 2] == 'S') str += 'W';
			else str += 'S';
		}
		else if (str[i - 1] == 'W' && s[i - 1] == 'x') {
			str += str[i - 2];
		}
	}

	return str;

	/*
	if (str[i - 1] == 'S' && s[i - 1] == 'o') return gen(str + str[i - 2], i + 1);
	else if (str[i - 1] == 'S' && s[i - 1] == 'x') {
		if (str[i - 2] == 'S') return gen(str + 'W', i + 1);
		else return gen(str + 'S', i + 1);
	}
	else if (str[i - 1] == 'W' && s[i - 1] == 'o') {
		if (str[i - 2] == 'S') return gen(str + 'W', i + 1);
		else return gen(str + 'S', i + 1);
	}
	else if (str[i - 1] == 'W' && s[i - 1] == 'x') {
		return gen(str + str[i - 2], i + 1);
	}
	*/
}

bool check(string str) {
	str += str.substr(0, 2);

	for (int i = 1; i <= n; i++) {
		if (str[i] == 'S') {
			if (s[i % n] == 'o' && str[i - 1] != str[i + 1]) return false;
			if (s[i % n] == 'x' && str[i - 1] == str[i + 1]) return false;
		}
		else if (str[i] == 'W') {
			if (s[i % n] == 'o' && str[i - 1] == str[i + 1]) return false;
			if (s[i % n] == 'x' && str[i - 1] != str[i + 1]) return false;
		}
	}

	return true;
}

int main(void){
	cin>>n>>s;

	string S = gen("SS");
	if (check(S)) {
		cout<< S <<endl;
		return 0;
	}

	S.clear();
	S = gen("SW");
	if (check(S)) {
		cout<< S <<endl;
		return 0;
	}

	S.clear();
	S = gen("WS");
	if (check(S)) {
		cout<< S <<endl;
		return 0;
	}

	S.clear();
	S = gen("WW");
	if (check(S)) {
		cout<< S <<endl;
		return 0;
	}

	cout<< -1 <<endl;
	
	return 0;
}