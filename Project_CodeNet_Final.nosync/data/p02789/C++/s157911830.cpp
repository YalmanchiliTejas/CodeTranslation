#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <iomanip>
using namespace std;

typedef long long ll;

#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
 
long gcd(long long a, long long b){
	if (a%b==0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}
}
 
long lcm(long long a, long long b){
	return a / gcd(a,b) * b;
}
 
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a < b) { a = b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a > b) { a = b; return 1; } return 0; }
 
const ll INF = 1ll<<60;
const ll MOD = 1000000007;
const double EPS = 1e-10;

int n, m;

int main(){
	int n, m;
	cin >> n >> m;

	if (n == m) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}