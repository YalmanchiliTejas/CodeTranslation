#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
	int n; cin >> n;
    vector<string> s(n);

	rep(i,n) cin >> s[i];

	string ans;

	for (char c = 'a'; c <= 'z'; c++){
		int small = 1002003004;

		rep(i,n){
			int cnt = 0;

			for (int j = 0; j < s[i].size(); j++){
				if (s[i][j] == c)cnt++;

			}
			small = min(small, cnt);
		}

		rep(i,small){
			ans += c;
		}

	}

    cout << ans << endl;
}
    