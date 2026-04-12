#include <iostream> 
#include <vector> 
#define m 1000000007
using namespace std;
using ll = long long ;

int main () 
{ 
	int n;
	ll sum = 0,x;
	vector<ll> v;

	cin >> n ;

	cin >> x;
	v.push_back(x);
	for( int i=1 ; i<n ; i++ )
	{
		cin >> x;
		v.push_back( (x+v[i-1])%m );
	}

	// for( auto o : v)
	// 	cout << o << ' ';
	// puts("");

	sum = ( v[0]*( (v[n-1]-v[0]) %m) )%m;
	if(sum<0)
		sum+=m;
		// cout << sum << ' ';

	for( int i=1 ; i<n ; i++ )
	{
		sum = (sum+ ( ( (v[i]-v[i-1])*(v[n-1]-v[i]) ) % m ) )%m;
	if(sum<0)
		sum+=m;
		// cout << sum << ' ';
	}

	cout << sum << endl;

    return 0; 
}