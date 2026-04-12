#include <bits/stdc++.h>

#define REP(i, s,  n) for(int i = s;i < (n);i++)
#define VSORT(v) sort(v.begin(), v.end());
#define int64 long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> PP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//---------------------------------------------------------------
//---------------------------------------------------------------
int A, B, C, X, Y;

signed main(){
	cin >> A >> B >> C >> X >> Y;
	
	int ans = 0;
	// Ａ，Ｂの両方あれば、Ｃがお得
	if(A + B > C*2) {
		while(X > 0 && Y > 0) {
			ans += C*2;
			X--; Y--;
		}
	}
	// Ａ１枚よりＣ２枚が安い！
	if(A > C*2) {
		while(X > 0) {
			ans += C*2;
			X--;
		}
	}
	// Ｂ１枚よりＣ２枚が安い！
	if(B > C*2) {
		while(Y > 0) {
			ans += C*2;
			Y--;
		}
	}
	ans += X * A;
	ans += Y * B;
	
	cout << ans << endl;
	
	return 0;
}
