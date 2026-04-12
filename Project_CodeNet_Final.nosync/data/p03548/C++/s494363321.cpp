#include <iostream>
using namespace std;
typedef long long  ll;

#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)
int main()
{
	ll X, Y, Z; cin >> X >> Y >> Z;
	cout << (X - Z) / (Y + Z) << endl;
	return 0;
}