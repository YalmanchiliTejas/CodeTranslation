#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)	
#define T int t ;cin >> t;while(t--)
using namespace std ;
typedef long long ll;
typedef unsigned long long ull;
inline ll gcd(ll a,ll b){return b == 0? a:gcd(b, a % b);}
const int maxn = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const double eps = 1e-11;
const ll mod = 1e9 + 7;
int main()
{
	int n ;
	cin >> n ;
	if(n >= 30)
		cout << "Yes" << endl ;
	else
		cout << "No" << endl ;
	return 0 ;
}