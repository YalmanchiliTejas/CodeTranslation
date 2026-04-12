#include "bits/stdc++.h"

using namespace std;

#define int long long
#define ll long long
typedef pair<int, int> P;
#define mod 1000000007
#define INF (1LL<<60)

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl



signed main(){

	int N;
	vector<int> H;
	cin >> N;
	rep(i, N){
		int t;
		cin >> t;
		H.push_back(t);
	}

	int ans = 1;
	for (int i = 1; i < N; i++){
		bool good = true;
		rep(j, i ){
			if (H[j] > H[i]){ good = false; break; }
		}
		if (good){
			ans++;
			cerr << i << endl;
		}
	}
	cout << ans << endl;


	return 0;
}