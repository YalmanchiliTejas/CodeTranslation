 #include <bits/stdc++.h>
 
using namespace std;

/* * * *   * * *   	* * * */
#define ll long long
#define ld long double
#define II pair<int, int>
#define LL pair<ll, ll>
#define VI vector<int>
#define VB vector<bool>
#define VS vector<string>
#define VL vector<ll>
#define VII vector<II>
#define VLL vector<LL>
#define PB push_back
#define B begin()
#define E end()
#define F first
#define S second
#define SZ size()
#define P complex <ll> 
#define X real()
#define Y imag()
const int oo = 1e9;
const ll mod = 1e7;
/* * * *   * * *   	* * * */

/* *
 *
 * Author: Hamkor
 *
 * */
 
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int h, w; cin>>h>>w;
	VS a(h);
	for(int i=0; i<h; ++i) cin>>a[i];
	VB r(h, 0), c(w, 0);
	for (int i=0;i<h;++i) for (int j=0; j<w; ++j) if (a[i][j] == '#') {r[i] = 1; c[j]=1;}
	for (int i=0; i<h; ++i){ 
		if (!r[i]) continue;
		for (int j=0; j<w; ++j) {
			if (!c[j]) continue;
			cout<<a[i][j];
		}
		cout<<"\n";
	}
	return 0;
}
