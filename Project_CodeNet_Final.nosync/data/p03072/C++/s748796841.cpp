#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

int N;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;

	vector<int> H(N);

	for(auto &x: H) cin >> x;

	int ans = 0,under = H[0];
	REP(i,N){
		if(H[i] >= under){
			ans++;
		 	under = H[i];
		}		
	}
	cout << ans << endl;

}