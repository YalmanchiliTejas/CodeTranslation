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
#define chmin(x,y) (x=min(x,y))
#define chmax(x,y) (x=max(x,y))
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}

int main(){
	ll l;
	string s, t;
	cin>>l>>s>>t;
	if(s+t>t+s) swap(s, t);
	int n = s.size(), m = t.size();
	int g = __gcd(n, m);
	int a = n/g, b = m/g, c = l/g;
	string res; 
	rep(i, c+1){
		if((c-(a*i))%b==0){
			int j = (c-(a*i))/b;
			rep(k, i) res+=s;
			rep(k, j) res+=t;
			break;
		}
	}
	for(int i = c/a; i >= 0; i--){
		if((c-(a*i))%b==0){
			int j = (c-(a*i))/b;
			string res2;
			rep(k, i) res2+=s;
			rep(k, j) res2+=t;
			if(res2<res) res = res2;
			break;
		}
	}
	cout<<res<<endl;
	return 0;
}
