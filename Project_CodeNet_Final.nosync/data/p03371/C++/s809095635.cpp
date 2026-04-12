#include"bits/stdc++.h"
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep3(i,m,n) for(int (i)=m;(i)<=(n);(i)++)
#define rep3rev(i,m,n) for(int (i)=m;(i)>=(n);(i)--)
#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

void Main(){
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int z = min(x,y);
	ll ans = 0;
	if(a+b >= 2*c) {
		ans += z*2*c;
		if(a>=2*c) ans += (x-z)*2*c;
		else ans += (x-z)*a;
		if(b>=2*c) ans += (y-z)*2*c;
		else ans += (y-z)*b;
    }
	else{
		ans += x*a + y*b;
	}
	cout << ans << endl;
	return;
}

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
	return 0;
}