#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define log(x,b) (log(b)/log(x))
#define rep(i,x,y) for(int i=(x);i<(y);i++)
using namespace std;
const int mod=1e9+7;
string s[55];
int32_t main()
{	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	string ans = "";
	for (char c = 'a'; c <= 'z'; c++) {
		int mi = mod;
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < s[i].size(); j++) {
				if (s[i][j] == c) {
					count++;
				}
			}
			mi = min(mi, count);
			count = 0;
		}
		for (int k = 0; k < mi; k++) {
			ans += c;
		}
	}
	cout << ans << endl;
    return 0;
}
