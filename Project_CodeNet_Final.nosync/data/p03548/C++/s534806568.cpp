#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define fast_cin ios_base::sync_with_stdio(false)

const int MOD = 1e9+7;

typedef long long ll;

bool comp(ll a, ll b){

	return a > b;
}
int main(int argc, char const *argv[])
{
	ll x,y,z;
	cin >> x >> y >> z;
	if ((x % (y + z)) < z)
	{
		cout << (x/ (y+z)) - 1 << endl;
	}
	else{
		cout << (x/ (y+z)) << endl;
	}
	return 0;
}