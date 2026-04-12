#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll X, Y, Z; cin >> X >> Y >> Z;

	ll res = 0LL;
	ll low = 0LL;
	ll high = X;

	int iter = 0;
	while(low < high && iter < 30){
		ll mid = (low + high) / 2LL;
		if (mid * Y + Z * (mid + 1LL) <= X){
			res = mid;
			low = mid;
		}else{
			high = mid;
		} // end if
		++iter;
	} // end while
	
	cout << res << endl;

	return 0;
}