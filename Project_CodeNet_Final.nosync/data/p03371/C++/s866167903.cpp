#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

const ll INF = 1e+9;

int main(){
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	
	int ans = INF;
	//ABピザをi枚買うとする
	for (int i = 0; i <= max(2*x,2*y) ; ++i) {
		int kakaku = i*c + max(0,(x-i/2))*a + max(0,(y-i/2))*b;
		ans = min(ans,kakaku);
	}
	
	cout << ans << endl;
    return 0;
}
