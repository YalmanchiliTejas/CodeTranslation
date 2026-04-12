#pragma GCC optimize("O3")
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<vector>
#include<sstream>
#include<queue>
#include <iomanip>
#include <fstream>
#include<unordered_set>
#include<stack>
#include <map>
#include<time.h>
#include <chrono>
constexpr auto INF = 9223372036854775807;
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned long int ul;
#define f(i,a,b) for(ll i=(ll)a;i<(ll)b;i+=1)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i-=1)
#define endl '\n'
#define N 1000000007 // prime modulo value 
#define all(x) x.begin(),x.end()
using namespace std;
#define MAX 1000001 
#define M 998244353
ll inverse(ll n)
{
	ll modu = M;
	ll m = modu;
	ll a = 0, b = 1;
	if (modu == 1)
		return 0;
	while (n > 1)
	{
		ll quo = n / modu;
		ll temp = modu;
		modu = n % modu, n = temp;
		temp = a; 
		a = b - (quo * a);
		b = temp;
	}
	if (b < 0)
		b += m;
	return b;
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;
	if (n == m)
	{
		cout << "Yes";
	}
	else
		cout << "No";
	return 0;
}
