#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	int n,k;cin>>n>>k;
	ll ans = 0;
	for(int b = 1; b <= n; b++) {
		int p = n / b;
		int r = n % b;
		ans += (p * max(0,b - k) + max(0,r - k + 1));
		if (k == 0)ans--;

	}

	cout << ans << endl;
	return 0;
}