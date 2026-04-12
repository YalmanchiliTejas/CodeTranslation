#include <bits/stdc++.h>
#include <typeinfo>
#include <cxxabi.h>
#ifdef LOCAL
#include "dbgtoki.hpp"
#define DUMP(i) dump((string)TOSTRING(i), demangle(typeid(i).name()), __LINE__ , i) 
#else
#define DUMP(i)
#endif

using namespace std;
#define TOSTRING(x) #x
#define SZ(x) (int)(x).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(s) (s).begin(), (s).end()
#define dis distance
#define so(V) sort(ALL(V))
#define rev(V) reverse(ALL(V))
#define uni(v) v.erase( unique(ALL(v)) , v.end());
#define pub push_back
#define sec second
#define fir first

typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector <int> > vvi;
const int EPS = 1e-9;
const int MOD = 1e9+7;
const int INF = (1 << 30);
const double PI = acos(-1);

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	REP(i,SZ(s)-1){
		if(s[i]=='A' && s[i+1]=='C'){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}