#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;
#define rep(i,n) for(int (i)=0;(i)<(ll)(n);++(i))
#define repd(i,n,d) for(ll (i)=0;(i)<(ll)(n);(i)+=(d))
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset((m),(v),sizeof(m))
#define chmin(X,Y) ((X)>(Y)?X=(Y),true:false)
#define chmax(X,Y) ((X)<(Y)?X=(Y),true:false)
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}
ll n;
vector<ll> v(n);

int main(){
	cin>>n;
	v = vector<ll>(n);
	rep(i, n) cin>>v[i];
	ll ub = 0;
	rep(i, n) ub += v[i];
	ll lb = max(0LL, ub - (n-1)*(n));
	rep(i, n) v[i] += lb;
	ll res = 0;
	rep(i, n){
		res += v[i]/(n+1);
		v[i] %= n+1;
	}
	rep(i, n) v[i] += res-lb;
	bool f;
	do{
		f = false;
		rep(i, n){
			if(v[i]>=n){
				res++;
				v[i] -= n+1;
				rep(j, n) v[j]++;
				f = true;
			}
		}
	} while(f);
	cout<<res<<endl;
	return 0;
}
