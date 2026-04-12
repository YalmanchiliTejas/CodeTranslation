#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int h,w;
	cin >> h >> w;
	vector<vector<char>> a(h,vector<char>(w));
	REP(i,h){
		string s;
		cin >> s;
		REP(j,w){
			a[i][j] = s[j];
		}
	}
	
	vector<bool> hflag(h,true);
	vector<bool> wflag(w,true);
	REP(i,h){
		REP(j,w){
			if(a[i][j] == '#'){
				break;
			}
			if(j==w-1){
				hflag[i] = false;
			}
		}
	}
	REP(j,w){
		REP(i,h){
			if(a[i][j] == '#'){
				break;
			}
			if(i==h-1){
				wflag[j] = false;
			}
		}
	}
	
	REP(i,h){
		REP(j,w){
			if(hflag[i] && wflag[j]){
				cout << a[i][j];
			}
		}
		if(hflag[i]) cout << endl;
	}
	
	
	
	
	
	return 0;
}