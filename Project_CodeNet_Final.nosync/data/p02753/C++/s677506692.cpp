#pragma GCC optimize("O3")
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>
#include<set>
#include<vector>
#include<sstream>
#include<queue>
#include <iomanip>
#include<unordered_set>
constexpr auto INF = 9223372036854775807;
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned long int ul;
#define f(i,a,b) for(ll i=(ll)a;i<(ll)b;i+=1)
#define endl '\n'
#define all(x) x.begin(),x.end()
using namespace std;
inline int mex(unordered_set<int> st)
{
	int m = 0;
	while (st.find(m) != st.end())
	{
		m += 1;
	}
	return m;
}
inline int calculateGrundy(int n)
{
	if (n == 1)
		return 0;
	unordered_set<int> mexi;
	for (int i = 1; i <= sqrt(n); i += 1)
	{
		if (n % i == 0)
		{
			if(n/i!=n)
				mexi.insert(calculateGrundy(n/i));
			mexi.insert(calculateGrundy(i));
		}
	}
	return mex(mexi);
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll test;
	string s;
	cin >> s;
	set<char> st;
	st.insert(s[0]);
	st.insert(s[1]);
	st.insert(s[2]);
	if (st.size() == 1)
	{
		cout << "No";
	}
	else
		cout << "Yes";
	return 0;
}