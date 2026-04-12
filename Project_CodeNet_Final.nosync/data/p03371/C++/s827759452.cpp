#include <bits/stdc++.h>

#define rep(i, a, n)  for(ll i=a; i<n; i++)
#define per(i, a, n)  for(ll i=n-1; i>=a; i--)
#define fill0(n)  setfill('0') << right << setw(n)
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define LONGMAX 1e18
#define INTMAX 1000000000

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod = 1e9+7;
const long double EPS = 0.0000000001;

int a,b,c,x,y;
int main(){
	cin >> a >> b >> c >> x >> y;
	int ans = INTMAX;
	for(int i = 0; i <= 2 * max(x,y); i=i+2){
		int tmp = i * c;
		tmp += max((x - i/2),0) * a;
		tmp += max((y - i/2),0) * b;
		ans = min(ans, tmp);
	}
	cout << ans << endl;
}