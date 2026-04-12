#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define F first
#define S second
#define pb push_back
#define mp make_pair

ll gcd(ll a, ll b){
	if (a == 0) return b;
	return gcd(b%a, a);
}

ll lcm(ll a, ll b){
	return (a/gcd(a, b))*b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;

	if(n >= 30)
		cout << "Yes\n";
	else
		cout << "No\n";
}