#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int inf = 1 << 26;

int n;
string s[105];
int each[1005];
int t[105][1005];

inline void quick_IO() { ios::sync_with_stdio(false); cout.tie(0); cin.tie(0); }

int main(){
	scanf("%d", &n);
	for ( int i = 0; i < n; i ++ ) cin >> s[i];
	for ( int i = 0; i < n; i ++ ) {
		for ( int j = 0; j < s[i].size(); j ++ ) {
			t[i][s[i][j]] ++;
		} 
	} 
	
	string ans = "";
	for ( int i = 0; i < 26; i ++ ) {
		int cnt = (1<<26);
		for ( int j = 0; j < n; j ++ ) {
			cnt = min(cnt, t[j][i+'a']);
		}
		for ( int j = 0; j < cnt; j ++ ) ans += (i+'a');
	}
	cout << ans << endl;
		
	return 0;
}
