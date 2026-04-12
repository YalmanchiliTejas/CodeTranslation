#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

const int MAX_N = 60;

ll a[MAX_N], p[MAX_N];



ll dfs(ll l, ll k){
	if (l==0) return 1;
	if (k==1) return 0;
	if (1<k&&k<=1+a[l-1]) return dfs(l-1, k-1);
	else if (k==2+a[l-1]) return p[l-1]+1;
	else if (k<=2+2*a[l-1]) return p[l-1]+1+dfs(l-1, k-a[l-1]-2);
	else return 2*p[l-1]+1;
}

int main(int argc, char const *argv[])
{
	ll n, x;
	cin >> n >> x;
	p[0] = 1;
	a[0] = 1;
	for (int i = 1; i <= n; ++i){
		p[i] = 2*p[i-1] + 1;
		a[i] = 2*a[i-1] + 3;
	}

	cout << dfs(n, x) << endl;
	return 0;
}