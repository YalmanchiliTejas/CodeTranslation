#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
 
using namespace std;

#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)

long gcd(long a, long b){
	if (a%b==0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}
}

long lcm(long a, long b){
	return (a*b) / gcd(a,b);
}
 
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a < b) { a = b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a > b) { a = b; return 1; } return 0; }
 
typedef long long ll;
 
const ll INF = 1ll<<29;
const ll MOD = 1000000007;
const double EPS = 1e-10;

int main(){
	int r, g, b;
	
	cin >> r >> g >> b;
	
	int sum = r*100+g*10+b;
	
	if (sum%4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}