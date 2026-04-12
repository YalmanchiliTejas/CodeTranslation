#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 60)

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



char s[3];
void solve(){
	cin >> s[0] >> s[1] >> s[2];
	bool b = 0,c = 0;
	for(int i = 0; i < 3; i++){
		if(s[i] =='A') b = 1;
		if(s[i] == 'B') c = 1;
	}
	if(b&&c) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
