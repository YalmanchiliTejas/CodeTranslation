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
 
using namespace std;
 
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define mp make_pair
#define all(r) r.begin(),r.end()
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

double EPS = 1e-10;

pii d[100100];

int main(){
	int n, t, ans;
	while(cin>>n && n){
		d[0].fi=-1;
		d[0].se = 0;
		for(int i = 1; i <= n; i++) {
			cin>>t;
			d[i].fi=t;
			if(i%2==1){
				if(d[i].fi!=d[i-1].fi) d[i].se = 1;
				else d[i].se = d[i-1].se+1;
			}
			else{
				if(d[i].fi==d[i-1].fi) d[i].se = d[i-1].se+1;
				else d[i].se = d[i-1].se+d[i-1-d[i-1].se].se+1;
			}
		}
		ans = 0;
		int idx = n;
		while(idx > 0){
			if(d[idx].fi==0) ans += d[idx].se;
			idx -= d[idx].se;
		}
		cout<<ans<<endl;
	}
}