#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define watch3(x,y,z) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<" and "<<(#z)<<" is "<<(z)<<"\n"

#define ll long long
#define ff first
#define ss second
#define null NULL
#define all(c) (c).begin(),(c).end()
#define nl "\n"

#define ld long double
#define eb emplace_back
#define pb push_back
#define pf push_front
#define mod 1000000007

typedef vector<ll> vl;
typedef vector< vl > vvl;
typedef pair< ll, ll> pll;
typedef map< ll, ll> mll;

#define pie_value 3.14159265358979323846

int main() {

	// Use ctrl+shift+b ( second option )
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt" , "w" , stderr);
#endif

	ll n;
	cin >> n;

	if (n >= 30)
		cout << "Yes" << nl;
	else {
		cout << "No" << nl;
	}


	return 0;
}
