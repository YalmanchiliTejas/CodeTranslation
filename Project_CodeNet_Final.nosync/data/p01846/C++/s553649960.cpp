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
#include <cassert>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define mp make_pair
#define all(r) (r).begin(),(r).end()
#define rall(r) (r).rbegin(),(r).rend()
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
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;
const double PI = acos(-1);

vector<string> split(const string& s, char c = '/'){
	vector<string> ret;
	string t;
	stringstream ss(s);
	while(getline(ss, t, c)) ret.pb(t);
	return ret;
}

int main(){
	string s;
	while(cin>>s && s!="#"){
		vector<string> t = split(s);
		vector<string> v(t.size());
		for(int i = 0; i < t.size(); i++){
			int cnt = 0;
			for(int j = 0; j < t[i].size(); j++){
				if(t[i][j] >= '0' && t[i][j] <= '9') (cnt *= 10)+=(t[i][j]-'0');
				else{
					if(cnt != 0) v[i] += string(cnt,'.');
					v[i] += 'b';
					cnt = 0;
				}
			}
			if(cnt != 0)v[i] += string(cnt, '.');
		}
		int a, b, c,d;
		cin>>a>>b>>c>>d;
		a--; b--; c--; d--;
		// cout<<endl;
		// for(int i = 0; i < v.size(); i++){
		// 	cout<<v[i]<<endl;
		// }
		assert(v[a][b]=='b');
		v[a][b] = '.';
		v[c][d] = 'b';
		string ans;
		for(int i = 0; i < v.size(); i++){
			int cnt = 0;
			for(int j = 0; j < v[i].size(); j++){
				if(v[i][j] == 'b'){
					if(cnt != 0) ans += ('0'+cnt);
					ans += 'b';
					cnt = 0;
				}
				else cnt++;
			}
			if(cnt != 0) ans += ('0'+cnt);
			if(i + 1 != v.size()) ans += '/';
		}
		cout<<ans<<endl;
	}

}