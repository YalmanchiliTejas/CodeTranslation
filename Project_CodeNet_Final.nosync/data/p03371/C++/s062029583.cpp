#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	ll A,B,C,X,Y;
	cin >> A >> B >> C >> X >> Y;
	ll ans = 1e15;
	rep(i,100005)
	{
		ll temp = 2 * C * i;
		temp += A * max(ll(0),X-ll(i));
		temp += B * max(ll(0),Y-ll(i));
		ans = min(ans,temp);
	}
	cout << ans << endl;
	return 0;
}