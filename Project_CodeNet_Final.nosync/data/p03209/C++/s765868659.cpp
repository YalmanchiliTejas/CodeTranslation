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
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pb push_back
#define pf push_front

namespace mp = boost::multiprecision;
using cpp_int = mp::cpp_int;
using ll = long long;
using namespace std;

ll M = 1000000007;
template <class T>
void print(const T &value)
{
	std::cout << value << std::endl;
}
int GCD(int x, int y)
{
	return x ? GCD(y % x, x) : y;
}
ll p[51],a[51];
ll f(ll n, ll x){
	if(n==0){
		if(x<=0)return 0;
		else return 1;
	}else if(x<=1+a[n-1]){
		return f(n-1,x-1);
	}else{
		return p[n-1]+1+f(n-1,x-2-a[n-1]);
	}
}
int main()
{
	ll n ,x;
	cin>>n>>x;
	p[0]=1;
	a[0]=1;
	FOR(i,1,51){
		p[i]=(ll)p[i-1]*2+1;
		a[i]=(ll)a[i-1]*2+3;
	}

	cout<<f(n,x)<<endl;
}
