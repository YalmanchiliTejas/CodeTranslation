#include "bits/stdc++.h"
//#include "atcoder/all"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
//using namespace atcoder;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if(n == m) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
