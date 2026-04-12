#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <ctime>

using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define mp make_pair
#define all(r) (r).begin(),(r).end()
#define rall(r) (r).rbegin(),(r).rend()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;
const double PI = acos(-1);

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

struct S
{
	string s;
	int p, id;
	bool operator < (const S&s) const{
		return s.p == p ? id < s.id : p > s.p;
	}
};

int main(){
	int n;
	bool l = false;
	while(cin>>n&&n){
		if(l) cout<<endl;
		else l =true;
		vector<S> v;
		string s;
		int a, b,c;
		rep(i, n){
			cin>>s>>a>>b>>c;
			v.pb({s, a*3+c, i});
		}
		sort(all(v));
		rep(i, n){
			cout<<v[i].s<<","<<v[i].p<<endl;
		}
	}
}