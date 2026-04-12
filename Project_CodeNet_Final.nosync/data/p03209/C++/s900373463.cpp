#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <numeric>
#include <bitset>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
#define FOR(i,a,b)   for(ll i = (a); i < (b); i++ )
#define REP(i, n)    FOR(i,0,n)
typedef pair< ll, ll >   cp2;
typedef pair< ll, cp2 >   cp3;
#define fi first
#define se second
#define sec  se.fi
#define thr  se.se
const ll mod = 1000000007;
//              123456789

 
///////////////////////////////////////////////
//
//
///////////////////////////////////////////////

////////////////////////////////////////////////
////////////////////////////////////////////////

ll N, X;
ll ans = 0;
ll B[51];
ll P[51];
ll before;

int main(){
	
	cin>>N>>X;
	
	
	FOR( i, 1, N+1 ){
		B[i] = 2ll*(1ll<<(i-1))+(1ll<<i)-2;
		P[i] = 4ll*(1ll<<(i-1))-1;
	}
	
	before = N;
	
	while( X > 0 ){
		ll temp = before;
		while( temp ){
			ll sum = before-temp+B[temp]+P[temp];
			if( X >= sum ){
				before = temp;
				ans += P[temp];
				X -= sum;
				if( X > 0 ){
					ans++;
					X--;
				} 
				break;
			}
			temp--;
		}
		if( temp == 0 ) break;
	}
	
	X -= before;
	
	ans += max( 0ll, X );
	
	cout<<ans<<endl;
	
	return 0;
}
