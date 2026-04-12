#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int A[26] = { 0 };
string S[60];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> S[i];
	int count[60][26] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < S[i].size(); j++) {
			count[i][(S[i][j] - 'a')]++;
		}
	}
	int min = mod;
	for (int i = 0; i < 26; i++) {
		min = mod;
		for (int j = 0; j < n; j++) {
			if (count[j][i] < min)min = count[j][i];
		}
		A[i] = min;
	}
	string ans;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < A[i]; j++) {
			ans.push_back((char)i + 'a');
		}
	}
	cout << ans << endl;
}
