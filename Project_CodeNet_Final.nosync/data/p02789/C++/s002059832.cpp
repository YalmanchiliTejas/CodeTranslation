#include <bits/stdc++.h>

#define sz(s) (int)(s).size()
#define re(i, n) for (int i = 1; i <= n; i ++)
#define pb push_back
#define finish(x) return cout << x << endl, 0
#define MP make_mair
#define trav(x, a) for(auto& x: a)
#define all(x) (x).begin,(x).end()
#define Sor(x) sort(all(x))
#define REV(x) reverse(all(x))
#define F first
#define S second
#define I insert
#define N 222222
#define MOD 100000007

using namespace std;

typedef long long ll;
vector <ll> vll;
template <class T> bool umin(T& a, T b) {if(a>b){a = b; return 1;}return 0;}
template <class T> bool umax(T& a, T b) {if(a<b){a=b; return 1;}return 0;}
template <class T, class TT> bool pal(T a, TT n){int k = 0; for(int i =0; i <= n / 2; i ++){if(a[i]!=a[n-i-1]){k=1;break;}}return k?0:1;}

ll powmod(ll a, ll b, ll m = MOD){ll r = 1;while(b>0){if(b&1)r=r*a%m;a=a*a%m;b>>=1;}return r;}


int main()
{	
	ll n, m;
	cin >> n >> m;
	if (n > m)
		cout << "No";
	else	
		cout << "Yes";









	getchar();
	getchar();
	return 0;
}