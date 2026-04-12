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

ll A, B, C;
ll X, Y;
ll N;
ll ans = mod*mod;

int main(){
	
	cin>>A>>B>>C;
	cin>>X>>Y;
	
	N = max( X, Y );
	
	REP( i, N+1 ){
		ll a = max( 0ll, X-i );
		ll b = max( 0ll, Y-i );
		ll num = i*2*C+a*A+b*B;
		ans = min( num, ans );
	}
	
	cout<<ans<<endl;
	
}


