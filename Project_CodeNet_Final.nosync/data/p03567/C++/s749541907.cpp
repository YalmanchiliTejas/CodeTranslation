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
#include <cstdint>
#include <unordered_map>
#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>

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

typedef pair<int, int> P;

bool ps1(const P &element1, const P &element2)
{ //first昇順
	return element1.first < element2.first;
}
bool ps2(const P &element1, const P &element2)
{ //first降順
	return element1.first > element2.first;
}
bool ps3(const P &element1, const P &element2)
{ //second昇順
	return element1.second < element2.second;
}
bool ps4(const P &element1, const P &element2)
{ //second降順
	return element1.second > element2.second;
}
int digits(int n)
{
	int count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return count;
}
ll combination(ll n, ll r)
{
	if (r * 2 > n)
		r = n - r;
	ll dividend = 1;
	ll divisor = 1;
	for (ll i = 1; i <= r; ++i)
	{
		dividend *= (n - i + 1);
		divisor *= i;
	}
	return dividend / divisor;
}
int GCD(int x, int y)
{
	return x ? GCD(y % x, x) : y;
}
vector<int> divisor(int n)
{
	vector<int> value;
	FOR(i, 1, pow(n, 0.5) + 1)
	{
		if (i <= sqrt(n))
		{
			if (n % i == 0)
			{
				value.push_back(i);
				if (i * i != n)
				{
					value.push_back(n / i);
				}
			}
		}
	}
	return value;
}
int main()
{
	string s;
	cin>>s;
	bool ans=false;
	rep(i,s.size()-1){
		if(s.substr(i,2)=="AC"){
			ans=true;
		}
	}
	if(ans){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}