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

vector< vector<bool> > foot;
int H,W;


bool check(int y,int l,int r){
	REP(x,W){
		if(x >= l && x <= r){
			if(!foot[x][y])return false;
		}else{
			if(foot[x][y])return false;
		}
	}
	return true;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> H >> W;
	foot = vector< vector<bool> > (W,vector<bool>(H,false));;
	REP(i,H){
		REP(j,W){
			char c;
			cin >> c;
			if(c == '#')foot[j][i] = true;
		}
	}
	int x = 0;
	REP(y,H){
		int l = x;
		while(x<W-1){
			if(foot[x+1][y])x++;
			else break;
		}
		if(!check(y,l,x)){
			cout << "Impossible" << endl;
			return 0;
		}
	}
	cout  << "Possible" << endl;
	return 0;
}