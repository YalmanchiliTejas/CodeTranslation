#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int main(){
	string s;
	cin >> s;
	for(int i = 0; i < s.size()-1; ++i) {
		if(s[i] == 'A' && s[i+1] == 'C') {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	ios::sync_with_stdio(0);
}