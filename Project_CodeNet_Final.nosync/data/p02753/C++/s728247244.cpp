#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 1000000007;
const ll INF = 2147483647;
const ll LINF = 9223372036854775807;
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

int main() {
	string s; cin >> s;
	if(s[0]==s[1]&&s[1]==s[2]){
		cout << "No" << endl;
	}
	else{
		cout << "Yes" << endl;
	}
	return 0;
}