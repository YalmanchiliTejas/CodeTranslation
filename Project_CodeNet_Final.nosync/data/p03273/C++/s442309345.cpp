#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
	cout << fixed << setprecision(10);
	int h,w;
	cin >> h >> w;
	string s[h];
	rep(i,h) cin >> s[i];
	vector<int> hh(h,0), ww(w,0);
	rep(i,h){
		bool ok = 1;
		rep(j,w){
			if(s[i][j]=='#') ok = 0;
		}
		if(ok==1) hh[i] = 1; 
	}
	rep(i,w){
		bool ok = 1;
		rep(j,h){
			if(s[j][i]=='#') ok = 0;
		}
		if(ok==1) ww[i] = 1;
	}
	rep(i,h){
		if(hh[i]==1) continue;
		rep(j,w){
			if(ww[j]==1) continue;
			cout << s[i][j];
		}
		cout << endl;
	}
	return 0;
}