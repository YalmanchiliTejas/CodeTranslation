#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> pi;
typedef pair<int,int> vi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(vi c, vi d){
	return c.S < d.S;
}

int main() {
	int a, b, c, x, y, ans = 0;
	cin >> a >> b >> c >> x >> y;
	
	while(x > 0 || y > 0){
		if(x == 0){
			--y;
			if(2*c > b) ans += b;
			else ans += 2*c;
		}
		else if(y == 0){
			--x;
			if(2*c > a) ans += a;
			else ans += 2*c;
		}
		else{
			--x;
			--y;
			//cout << 2*c << " " << b +a << " " << ans <<endl;
			if(2*c > a+b) ans += b+a;
			else ans += 2*c;
			//cout << 2*c << " " << b +a << " " << ans <<endl;
		}
	}
	cout << ans;
			

}
