#include "bits/stdc++.h"
using namespace std;
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define N	    100001
#define rep(i,a,b)  for(int i=a;i<b;i++)
typedef long long ll;
void solve() {
	int n;
	cin>>n;
	vii v, ans;
	rep(i, 0, n) {
		int tem;
		cin>>tem;
		v.pb(mp(tem, i));
	}
	sort(all(v));
	rep(i, 0, n) {
		if(i < n / 2)
			ans.pb(mp(v[i].y, v[n / 2].x));
		else
			ans.pb(mp(v[i].y, v[n / 2 - 1].x));
	}
	sort(all(ans));
	rep(i, 0, n)
		cout<<ans[i].y<<endl;
}
int main() {
	int t;
//	cin>>t;
	t = 1;
	while(t--){
		solve();
	}
}
