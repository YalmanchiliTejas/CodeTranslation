#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define inf 1000000000000000000
#define ff first
#define ss second
void checkpoint1()
{
	/******think more code less******/
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
bool comp(pair< ll,ll > &a,pair< ll,ll > &b)
{
	if(a.ff!=b.ff)
		return a.ff<b.ff;
	else
	{
		if(a.ss>b.ss)
			return b.ss<a.ss;
		else if(a.ss<b.ss)
			return a.ss<b.ss;
	}
	return a.ff>b.ff;
}
int main()
{
	checkpoint1();
	ll n;
	cin>>n;
	if(n>=30)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}