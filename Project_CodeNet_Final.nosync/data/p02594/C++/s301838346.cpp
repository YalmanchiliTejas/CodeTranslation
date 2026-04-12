/*
    Author      : Dinesh Verra
    College     : ABV-IIITM
    Date        : 02/08/2020
    Source		: 
    Explanation : 
*/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp> 
// using namespace boost::multiprecision; 
using namespace std;
typedef long long ll;
// typedef unsigned long long ll;
#define cu continue
#define br break
#define pb push_back
#define eb emplace_back
#define mod 1000000007
#define inf INT_MAX
#define pll pair <ll,ll>
#define min_pq priority_queue <pll> ,vector <pll>, greater <pll> > > 
#define F first
#define S second
#define vll vector <ll>
#define vpll vector <pll>
#define dbg(n) cout<<#n<<' '<<n<<endl;
#define all(v) v.begin(),v.end()
#define nl cout<<'\n'

template <typename A1>
void prn(A1&& arg)
{
	cout<<arg<<'\n';
}
template <typename A1, typename... A>
void prn(A1&& arg, A&&... args)
{
	cout<<arg<<' ';
	prn(args...);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	ll x;
	cin>>x;
	if(x>=30) prn("Yes");
	else prn("No");
}