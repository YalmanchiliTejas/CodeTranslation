#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long int ll;
const ll MAX=1e12;

int main()
{
	ll A,B,C,x,y; cin>>A>>B>>C>>x>>y;
	ll cost=MAX;
	for(ll i=0;i<=2e5;i++){
		ll curcost = 2*i*C;
		ll z=0;
		curcost += A*max(z,x-i);
		curcost += B*max(z,y-i);
		cost=min(cost,curcost);
	}
	cout<<cost;
}
