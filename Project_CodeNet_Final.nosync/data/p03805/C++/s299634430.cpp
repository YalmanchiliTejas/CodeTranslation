#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int N,M;
	cin >> N >> M;
	map<pair<int,int>,int> mp;
	rep(i,M){
		int a,b;
		cin >> a >> b;
		a--;b--;
		mp[make_pair(a,b)]++;
		mp[make_pair(b,a)]++;
	}
	
	vector<int> d;
	rep(i,N){
		d.push_back(i);
	}
	
	int ans = 0;
	
	do{
		bool ok = true;
		if(d[0] != 0) continue;
		//間に辺がなかったらアウト
		rep(i,N-1){
			if(mp[make_pair(d[i], d[i+1])] == 0) ok = false;
		}
		if(ok) {
			ans++;
		}
	}while(next_permutation(d.begin(),d.end()));
	
	cout << ans << endl;
    return 0;
}


