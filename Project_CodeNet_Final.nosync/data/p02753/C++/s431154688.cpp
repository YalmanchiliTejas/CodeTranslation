#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define len(x) (int)(x.size())
#define all(vs) vs.begin(), vs.end()
using ii = pair<int, int>;
using ll = long long;

int32_t main(){
	string st;
	cin >> st;
	char c = st[0];
	bool ans = false;
	for(auto x:st) if(x!=c) ans = true;
	if(ans)
		cout << "Yes\n";
	else
		cout << "No\n";	
}
