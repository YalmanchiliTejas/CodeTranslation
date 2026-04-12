#include<bits/stdc++.h>
using ll = long long;
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define ALL(x) x.begin(),x.end()

#define INF (ll)1e9 //10^9:∞
#define LLINF (ll)1e12
#define MOD (ll)(1e9+7) //10^9+7:合同式の法
#define PI 3.141592653589
#define PB push_back
#define F first
#define S second
#define __MAGIC__ ios::sync_with_stdio(false);cin.tie(nullptr);

#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

#define Graph vector<vector<int>>
#define PII pair<int,int>
#define VI vector<int>
#define VVI vector<vector<int>>
#define VPII vector<pair<int,int>>

#define DDD fixed<<setprecision(10)
#define endl "\n"

using namespace std;
/*..................DEFINE GLOBAL VARIABLES...................*/


/*.....................DEFINE FUNCTIONS ......................*/



/*.........................kemkemG0...........................*/
signed main() {
	__MAGIC__


	int N;
	cin >> N;
	vector<string> v(N);
	REP(i, N) {cin >> v[i]; sort(ALL(v[i]));}

	vector<vector<int>> alphabet(N, VI('z' + 1, 0));

	string ans = {""};

	REP(i, N) {
		REP(j, v[i].size()) {
			alphabet[i][(int)v[i][j]]++;
		}
	}
	vector<int> list('z' + 1, INF);
	FOR(i, 'a', 'z') {
		REP(j, N) {
			list[i] = min(list[i], alphabet[j][i]);
		}
	}
	FOR(i, 'a', 'z') {
		REP(j,list[i]){
			ans+=(char)i;
		}
	}
	cout<<ans<<endl;

	return 0;
}
