#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define print(s) cout << s << endl
#define acc(v) accumulate(v.begin(), v.end(), 0)
#define cinv(n,v) rep(i,n) cin >> v[i]
using namespace std;
const int INF = 1e9;
typedef long long ll;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<char> vchar;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
// const lint MOD = 998244353;
int x_pos[4] = {1,0,-1,0}, y_pos[4] = {0,1,0,-1};
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}
char upper(char c){
	return c-0x20;
}
char lower(char c){
	return c+0x20;
}

int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x%y);
}

int main(){
	int a,b,c,x,y; cin>>a>>b>>c>>x>>y;
	int cost = 0;
	if (a+b >= c*2){
		if (x>=y){
			cost += y*c*2;
			x -= y;
			y = 0;
		}else{
			cost += x*c*2;
			y -= x;
			x = 0;
		}
	}else{
		if (x>=y){
			cost += y*(a+b);
			x -= y;
			y = 0;
		}else{
			cost += x*(a+b);
			y -= x;
			x = 0;
		}
	}
	if (x){
		if (a >= c*2){
			cost += c*2*x;
		}else{
			cost += a*x;
		}
	}else{
		if (b >= c*2){
			cost += c*2*y;
		}else{
			cost += b*y;
		}
	}
	cout << cost << endl;
 }
