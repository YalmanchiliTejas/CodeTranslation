/*input
7
10 4
11 28
24 22
8 6
4 28
8 22
11 11
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long 
#define double long double
#define f first
#define s second
#define mp make_pair
#define pb push_back

#define RE(i,n) for (int i = 1; i <= n; i++)
#define RED(i,n) for (int i = n; i > 0; i--)
#define REPS(i,n) for(int i = 1; (i*i) <= n; i++)
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)

#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int INF = 1e18+1;
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;

int raise(int a,int n,int m = MOD){
  if(n == 0)return 1;
  if(n == 1)return a;
  int x = 1;
    x *= raise(a,n/2,m);
    x %= m;
    x *= x;
    x %= m;
    if(n%2)x*= a;
    x %= m;
    return x;
}

int floor1(int n,int k){
    if(n%k == 0 || n >= 0)return n/k;
    return (n/k)-1;
}

int ceil1(int n,int k){
    return floor1(n+k-1,k);
}

const int N = 2e5+1;
int x[N];
int y[N];
vector< pair<int,int> > fuck;
int idk[N];
int idkk[N];
int mxx = 0;
int mnn = 1e9+1;
vector<int> all;
int n;
int mxdiff = 0;
vector<int> hehe;
vector<int> haha;

bool check(int l,int r){
	if(fuck[n-1].f > r)return 0;
	if(fuck[0].f >= l){
		return 1;
	}
	int lo = 0;
	int hi = n-1;
	while(lo < hi){
		int mid = (lo+hi)/2;
		if(fuck[mid].f >= l)hi = mid;
		else lo = mid+1;
	}
	return idk[lo-1] >= l and idkk[lo-1] <= r;
}

int ans = INF;

void case2(){
	int mx_x = hehe[n-1];
	int mn_y = haha[0];
	ans = min(ans,(mx_x-mnn)*(mxx-mn_y)); 
}

void solve(){
  	cin >> n;
  	RE(i,n){
  		cin >> x[i] >> y[i];
  		if(x[i] > y[i])swap(x[i],y[i]);
  		fuck.pb({x[i],y[i]});
  		hehe.pb(x[i]);
  		haha.pb(y[i]);
  		all.pb(x[i]);
  		all.pb(y[i]);
  	}
  	sort(all(fuck));
  	idk[0] = fuck[0].s;
  	idkk[0] = fuck[0].s;
  	RE(i,n-1){
  		idk[i] = min(idk[i-1],fuck[i].s);
  		idkk[i] = max(idkk[i-1],fuck[i].s);
  	}
  	//cout << check(1,6,2,5);
  	sort(all(all));
  	sort(all(hehe));
  	sort(all(haha));
  	mnn = all[0];
  	mxx = all[2*n-1];
  	REP(i,all.size()){
  		// [all[i],mxx] [mnn,binary]
  		// [mnn,mxx] [all[i],binary]
  		int lo = i;
  		int hi = all.size();hi--;
  		while(lo < hi){
  			int mid = (lo+hi)/2;
  			if(check(all[i],all[mid]))hi = mid;
  			else lo = mid+1;
  		}
  		if(check(all[i],all[lo])){
  			ans = min(ans,(mxx-mnn)*(all[lo]-all[i]));
  		}
  	}
  	case2();
  	cout << ans;
}

signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen(".in","r",stdin);freopen(".out","w",stdout);
  int t = 1;
  //cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
