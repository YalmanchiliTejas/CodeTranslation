/*---------------------------------

 @Author:   Dicer
 @DateTime: 2019-05-12 12:15:30

---------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline ll qpow(ll a,ll b,ll mod){ll res=1;while(b){if(b&1)res = (res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const int MAXN = 2e5 + 7;

int main(int argc, char const *argv[])
{
	int n, x, mmax = 0, res = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> x;
		if(x >= mmax){
			res++;
			mmax = max(mmax, x);
		}
	}
	cout << res << endl;
	return 0;
}