#include <bits/stdc++.h>

#pragma region Macro
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define SORT(v) sort(v.begin(), v.end())
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define vi vector<int>
#define vvi vector<vector<int>>
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#pragma endregion

void solve(){
	#define int ll
	// ここに処理を記述
	// コンパイル時はエイリアス「gpp」--> c++17でコンパイル
	
	int X;
	cin >> X;

	if(X >= 30){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
	
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	
	solve();
	return 0;
}