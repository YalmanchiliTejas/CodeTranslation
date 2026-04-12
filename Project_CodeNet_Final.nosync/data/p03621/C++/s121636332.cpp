#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>
 
using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
//#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;
 
const double PI = acos(-1);
const double EPS = 1e-9;
 
const int MX = 10005;
const int MM = 998244353;
 
ll F[MX], I[MX], IF[MX];
 
int main()
{
	I[1] = 1;
	for(int i = 2; i < MX; i++) I[i] = (MM - MM/i) * I[MM%i] % MM;
	F[0] = IF[0] = 1;
	for(int i = 1; i < MX; i++){
		F[i] = F[i-1] * i % MM;
		IF[i] = IF[i-1] * I[i] % MM;
	}
 
	string A, B;
	cin >> A >> B;
 
	int a = 0, b = 0;
	for(int i = 0; i < A.size(); i++){
		if( A[i] == '1' && B[i] == '1' ) a++;
		if( A[i] != B[i] ) b++;
	} b /= 2;
 
	vector<int> Y(MX, 0);
 
	for(int i = 0; i <= b; i++){
		ll m = F[b] * IF[b-i] % MM * IF[i] % MM;
		if( (b-i)%2 ) m = MM-m;
		for(int j = 0; j <= a+b; j++){
			Y[j] = (Y[j] + m * IF[j]) % MM;
			m = m * i % MM;
		}
	}
 
	ll ans = 0;
	for(int i = b; i <= a+b; i++){
		ans = (ans + Y[i]) % MM;
	}
	ans = ans * F[a+b] % MM * F[a] % MM * F[b] % MM;
	printf("%lld\n", ans);
}