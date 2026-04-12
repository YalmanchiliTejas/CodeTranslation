#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <cmath>
#include <numeric>
#include <iomanip>
#include <deque>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <sstream>
#include <stdexcept>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

#define rep(i, x) for (int i = 0; i < (int)(x); i++)
#define FOR(i, a, done) for (int i = (a); i < (done); ++i)
#define all(a) (a).begin(), (a).end()
#define x first
#define y second
#define debug(a) cout << (a) << endl
namespace mp = boost::multiprecision;
using cpp_int = mp::cpp_int;
using ll = long long;
using namespace std;
template <class T>
bool chmax(T &a, const T &b)
{
	if (a < b)
	{
		a = b;
		return 1;
	}
	return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
	if (a > b)
	{
		a = b;
		return 1;
	}
	return 0;
}

ll M = 1000000007;
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

void solve()
{
	int n;
	cin>>n;
	vector<ll>a(n);
	ll sum=0;
	ll sq=0;
	rep(i,n){
		cin>>a[i];
		sum+=a[i];
		sum%=M;
		sq+=a[i]*a[i]%M;
		sq%=M;
	}
	sum*=sum;
	sum%=M;
	sum-=sq;
	sum*=modinv(2,M);
	sum%=M;
	while(sum<0){
		sum+=M;
	}
	cout<<sum<<endl;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
