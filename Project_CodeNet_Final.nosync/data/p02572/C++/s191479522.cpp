#include <iostream>
#include <cstdlib>
#include <bitset>
#include <map>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std;

#define ll long long
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecchar vector<char>
#define vecstr vector<string>
#define vec2str vector<vector<string>>
#define vecbool vector<bool>
#define vec2bool vector<vector<bool>>
#define pairll pair<ll,ll>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)

#define Pi 3.1415926535897932384626

int main() {
	ll n,ans=0;
	string s,t;
	bool flag = false;

	cin >> n;

	vecll a(n),buf3(n);

	forll(i, 0, n)
		cin >> a[i];

	sort(a.begin(), a.end());

	ll buf = 0;

	forll(i, 0, a.size())
	{
		buf += a[i];
	}

	ll buf2 = 0;

	forll(i, 0, a.size())
	{
		buf2 += a[i];
		buf3[i] = buf - buf2;
		buf3[i] %= 1000000007;
	}

	forll(i, 0, a.size())
	{
		ans += buf3[i]*a[i];
		ans %= 1000000007;
	}
	cout << ans;
}