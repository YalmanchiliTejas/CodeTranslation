/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

vector<pii> t1, t2;
vector<pair<int,pii>> d1, d2;
int par[100000], sz[100000];
ll ans = 0;

int getpar(int a) {
    if (par[a] != par[par[a]]) par[a] = getpar(par[a]);
    return par[a];
}

void unite(int a, int b, int weight) {
    a = getpar(a), b = getpar(b);
    if (a == b) return;
    ans += weight;
    if (sz[a]<sz[b]) swap(a,b);
    sz[a] += sz[b];
    par[b] = a;
}

int main() {
	int N; cin >> N; t1.resize(N); t2.resize(N);
	F0R(i,N) par[i] = i, sz[i] = 1;
	
	F0R(i,N) {
	    cin >> t1[i].f >> t2[i].f;
	    t1[i].s = t2[i].s = i;
	}
	sort(t1.begin(),t1.end()); sort(t2.begin(),t2.end());
	
	F0R(i,t1.size()-1) d1.pb({t1[i+1].f-t1[i].f,{t1[i].s,t1[i+1].s}});
	sort(d1.begin(),d1.end());
	
	F0R(i,t2.size()-1) d2.pb({t2[i+1].f-t2[i].f,{t2[i].s,t2[i+1].s}});
	sort(d2.begin(),d2.end());
	
	int i1 = 0, i2 = 0;
	while (i1 < d1.size() || i2 < d2.size()) {
	    if (i1 == d1.size()) {
	        unite(d2[i2].s.f,d2[i2].s.s,d2[i2].f);
	        i2++;
	    } else if (i2 == d2.size()) {
	        unite(d1[i1].s.f,d1[i1].s.s,d1[i1].f);
	        i1++;
	    } else {
    	    if (d1[i1].f <= d2[i2].f) {
    	        unite(d1[i1].s.f,d1[i1].s.s,d1[i1].f);
    	        i1++;
	        } else {
	            unite(d2[i2].s.f,d2[i2].s.s,d2[i2].f);
	            i2++;
	        }
	    }
	}
	cout << ans;
}