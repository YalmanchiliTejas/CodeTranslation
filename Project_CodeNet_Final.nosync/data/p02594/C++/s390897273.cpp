#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
inline int readInt() {int x; cin >> x; return x;}
inline char readChar() {char c; cin >> c; return c;}
inline string readString() {string s; cin >> s; return s;}

int32_t main()
{
	//freopen("input.txt", "r", stdin);
	IOS;
	
	int x = readInt();
	if(x >= 30) cout << "Yes";
	else cout << "No";	
	return 0;
}