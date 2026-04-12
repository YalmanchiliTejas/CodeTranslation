#include <bits/stdc++.h>
using namespace std;
const int N = 55;

string s[N];
int cnt [N][28];

int main ()
{
	int n;
	cin >> n;
	for (int i = 0 ;i < n ; i++) {
		cin >> s[i];
		for (int j = 0; j < (int)s[i].size(); j++)
		{
			cnt[i][s[i][j]-'a']++;
		}
	}
	
	//abbaga
	for (int j = 'a'-'a'; j <= 'z'-'a'; j++) {
		int minn = 1e9;
		for (int i = 0; i < n; i++) {
			int cntt = cnt[i][j];
			minn = min(minn, cntt);
		}
		for (int i = 0; i < minn; i++) {
			cout << char(j+'a');
		}
	}
	cout << endl;
}
