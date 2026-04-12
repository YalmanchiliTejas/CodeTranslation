#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (ll i = 0; i < n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(a, b) for (ll i = a; i < b + 1; i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template<class T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}
template<class T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}


int main(){
	int n,m;
	cin >> n >> m;
	if(n==m){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}