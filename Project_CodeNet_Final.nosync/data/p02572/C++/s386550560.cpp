#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
typedef long long ll;
using namespace std;
ll a[200010];
#define MOD (1000000007)
int main()
{
	int N;
	cin>>N;
	ll sumA = 0;
	for( int i=0; i<N; i++ )
	{
		cin>>a[i];
		sumA = (sumA+a[i])%MOD;
	}
	ll ot = 0;
	for( int i=0; i<N; i++ )
	{
		ll tmp = (sumA + MOD-a[i])%MOD; 
		ot = ot + (tmp*a[i])%MOD;
		ot %= MOD;
	}
	if( ot%2 == 1 )
		cout << (ot+MOD)/2;
	else
		cout << (ot)/2;
	return 0;
}