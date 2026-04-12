#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define FOR(i, a, n) for(int i=a; i<n; i++)
#define RFOR(i, a, n) for(int i=n-1; i>=a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) FOR(i, 0, n)

void getCha(int num[26], string str) {
	for (int j = 0; j < str.size(); j++) {
		num[str[j] - 'a']++;
	}
	return;
}

int main()
{
	int n;
	int num1[26] = {};
	cin >> n;

	string s;
	cin >> s;
	getCha(num1, s);
	FOR(i, 1, n){
		int num2[26] = {};
		string str;
		cin >> str;
		getCha(num2, str);

		int number[26] = {};
		REP(j, 26) {
			if (num1[j] == 0 && num2[j] == 0) continue;
			else if (num1[j] == num2[j]) number[j] = num1[j];
			else if (num1[j] < num2[j]) number[j] = num1[j];
			else number[j] = num2[j];
		}
		REP(j, 26) num1[j] = number[j];
	}
	
	REP(i, 26) {
		RREP(j, num1[i]) {
			cout << (char)('a' + i);
		}
	}
	cout << endl;
	return 0;
}