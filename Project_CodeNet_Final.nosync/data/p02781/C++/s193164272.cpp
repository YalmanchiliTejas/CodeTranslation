#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using llpair=pair<ll,ll>;
using llvec=vector<ll>;
using llmat=vector<vector<ll>>;
#define llmattp(name,a,b,num) name(a,vector<ll>(b,num))
#define LLINF 1LL<<60
#define ABS(x) ( (x)>0 ? (x) : -(x) )

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

ll gcd(ll a, ll b) {
	if(a==0||b==0) return 0;
	if(a<b) swap(a,b);
	ll tmp = a%b;
	while(tmp!=0) {
		a = b;
		b = tmp;
		tmp = a%b;
	}
	return b;
}

ll factorial(ll x) {
	ll f=1;
	for(ll i=2; i<x; i++) {
		f*=i;
	}
	return f;
}

ll nPr(ll n, ll r) {
	ll result=1;
	for(ll i=r+1; i<=n; i++) result*=i;
	return result;
}

ll nCr(ll n, ll r) {

	if (n == 0) { return 0; }
	if (r == 0) { return 1; }
	if (r == 1) { return n; }
	if (n == r) { return 1; }

	if (r > n / 2) { r = n / 2; }

	double result = 1;
	for (double i = 1; i <= r; i++) {
		result *= (n - i + 1) / i;
	}

	return (ll)result;
}

bool IsPrime(ll num) {
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

	double sqrtNum = sqrt(num);
	for (ll i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			// 素数ではない
			return false;
		}
	}

	// 素数である
	return true;
}

ll GreaterBinarySearch(ll *array, ll key, ll max, ll min) {
	if(array[max]<array[min]) {
		return NULL;
	} else {
		ll mid = max + (min-max)/2;
		if(array[mid]<key) {
			return GreaterBinarySearch(array,key,max,mid-1);
		} if(array[mid]>key) {
			return GreaterBinarySearch(array,key,mid+1,min);
		} else {
			return mid;
		}
	}
}

string n;
int K;
bool flag;

ll dp[101][2][101]; // digit kakutei-flag !0num

int main() {
	for(int i=0; i<101; i++)
		for(int j=0; j<2; j++)
			for(int k=0; k<101; k++)
				dp[i][j][k]=0LL;
	dp[0][0][0]=1LL;
	cin>>n>>K;

	for(int i=0; i<n.length(); i++) {
		int D=n.at(i)-'0';
		for(int j=0; j<2; j++)
			for(int k=0; k<=i; k++) {
				for(int d=0; d<=(j?9:D); d++) {
					if(d!=0) dp[i+1][j||(d!=D)][k+1] += dp[i][j][k];
					else     dp[i+1][j||(d!=D)][k] += dp[i][j][k];
				}
			}
	}
	cout<<dp[n.length()][0][K]+dp[n.length()][1][K]<<endl;
}
