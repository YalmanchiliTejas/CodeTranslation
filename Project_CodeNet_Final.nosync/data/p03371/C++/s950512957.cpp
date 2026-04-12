#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (int i = 0; i < n; i++)
#define IREP(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(a, b) for (int i = a; i < b + 1; i++)
#define MOD 1000000007
#define int long long
using namespace std;
typedef long long ll;

signed main() {
	int a,b,c;
	int x,y;
	cin >> a >> b >> c >> x >> y;
	int ans;
	if(a+b<c*2){
		ans=(a+b)*min(x,y);
	}
	else{
		ans=c*min(x,y)*2;
	}
	if(x<y){
		ans+=min((y-x)*b,(y-x)*c*2);
	}
	else if(x>y){
		ans+=min((x-y)*a,(x-y)*c*2);
	}
	cout << ans << endl;
}