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

string gen(string str) { //最初の2匹から一意的に決めるためのgenerator

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
}

bool check(string str) {
	str += str.substr(0, 2); //円環状になっているため、はじめともう一個分足す。

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

	string S, tester[4] = { "SS", "SW", "WS", "WW" };
	for (int i = 0; i < 4; i++) {
		S.clear();
		S = gen(tester[i]); //"SS", "SW", "WS", "WW" のそれぞれについてチェック。
		if (check(S)) { //矛盾していないならそこで終了する
			can = true;
			break;
		}
	}

	if (can) cout<< S <<endl;
	else cout<< -1 <<endl;

	return 0;
}