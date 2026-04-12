#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n))
#define Vec(a,n) vector<string> (a)((n))
using namespace std;
signed main(){
	int h,w,ans=0;
	cin >> h >> w;
	Vec(a,h);
	REP(i,h){
		cin >> a[i];
	}
	REP(i,h){
		REP(j,w){
			if(a[i][j] == '#'){
				ans ++;
			}
		}
	}
	(ans == h+w-1)? cout << "Possible" << endl : cout << "Impossible" << endl;
    return 0;
}