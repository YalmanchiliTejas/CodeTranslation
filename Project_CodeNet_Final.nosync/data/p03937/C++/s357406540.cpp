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
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second
#define println(X) cout<<X<<endl;
#define DBG(X) cout<<#X<<" : "<<X<<endl;
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 

const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;
const double PI = acos(-1);

int main(){
	int h, w;
	cin>>h>>w;
	vector<string> s(h);
	rep(i, h) cin>>s[i];
	bool f = true;
	int r = 0, l = INF;
	for(int i = 0; i < w; i++){
		if(s[0][i] == '#'){
			l = min(l, i);
			r = max(r, i);
		}
	}
	int ll = INF, rr = 0;
	for(int i = 1; i < h; i++){
		for(int j = 0; j < w; j++){
			if(s[i][j] == '#'){
				ll = min(ll, j);
				rr = max(rr, j);
			}
		}
		if(ll < l) f = false;
		if(rr < r) f = false;
		if(ll != r) f = false;
		l = ll;
		r = rr;
		ll = INF;
		rr = 0;
	}
	cout<<(f?"Possible": "Impossible")<<endl;
}