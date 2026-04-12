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
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	if(a+b <= 2*c) cout << a*x + b*y << endl;
	else{
		int ans = a*x + b*y;
		for(int i=1; i<=max(x,y)*2;i++){
			int now = i*c;
			if(i%2!=0) continue;
			int xx = x - i/2, yy = y - i/2;
			if(xx > 0 ) now += xx*a;
			if(yy > 0 ) now += yy*b;
			ans = min(now,ans);
		}
		cout << ans << endl;
	}
	return 0;
}