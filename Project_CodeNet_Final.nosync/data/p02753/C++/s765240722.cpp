#include<bits/stdc++.h>

using namespace std;

#define ll					long long
#define vi					vector<int>
#define vii					vector<vi>
#define ALL(s)			(s).begin(),(s).end()
#define pii					pair<int, int>
#define pll					pair<ll, ll>
#define si					set<int>
#define mp					make_pair
#define F						first
#define S						second
#define pb					push_back
#define tc(t)				int t; cin >> t; while(t--)
#define _						ios_base::sync_with_stdio(false); cin.tie(NULL); 
const ll MOD = 1e9 + 7;
const ll INF = 1<<29;
const ll MAX_N = 1e6 + 7;


int main() {_
	string s;
	cin >> s;

	bool ok1 = false, ok2 = false;

	for(auto x : s) {
		if(x == 'A')
			ok1 = true;
		if(x == 'B')
			ok2 = true;
		if(ok1 && ok2)
			break;
	}

	if(ok1 && ok2)
		cout << "Yes\n";
	else
		cout << "No\n";
	
}
