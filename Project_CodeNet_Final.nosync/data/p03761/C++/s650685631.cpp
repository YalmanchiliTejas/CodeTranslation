#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n))
#define Vec(a,n) vector<string> (a)((n))
using namespace std;
signed main(){
	int n,c=0;
	cin >> n;
	vector<vector<int>> a(n);
	REP(i,n){
		REP(j,26){
			a[i].push_back(0);
		}
	}
	Vec(b,n);
	REP(i,n){
		cin >> b[i];
		int s = b[i].size();
		REP(j,s){
			char t = b[i][j];
			int u = t - 'a';
			a[i][u]++;
		}
	}
	if(n == 1){
		REP(i,26){
			char d = i + 97;
			while(a[0][i] != 0){
				cout << d;
				a[0][i]--;
			}
		}
		goto owa;
	}
	REP(i,26){
		c = min(a[0][i],a[1][i]);
		FOR(j,2,n){
			c = min(c,a[j][i]);
			
		}
		char d = i + 97;
			while(c != 0){
				cout << d;
				c--;
			}
	}
	owa:
    return 0;
}