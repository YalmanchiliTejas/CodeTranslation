//Created by rect0r
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define F first
#define S second
#define all(x) (x).begin(),(x).end()

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<char> vc;
typedef pair<int, int> pii;

void solve() {
	string s;
	cin >> s;
	int a[2]={0};
	for(int i=0; i<s.length(); i++)
		a[s[i]-'A']++;
	if(a[0]!=0 && a[1]!=0)
		cout << "Yes";
	else 
		cout << "No";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll T;
	//cin >> T;
	T = 1;
	while(T--) {
		solve();
		cout << '\n';
	}
	return 0;
}
