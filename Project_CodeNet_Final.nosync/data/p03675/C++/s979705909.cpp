#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

ofstream outfile;
ifstream infile;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int i, n, t, t2;
	cin >> n;
	deque <int> mydeq;

	
	for(i = 1; i <= n; ++i)
	{
		cin >> t;
		if( i % 2)
		{
			mydeq.pf(t);
		}
		else
		{
			mydeq.pb(t);
		}
	}

	if( n % 2)
	{
		for(i = 0; i < mydeq.size(); ++i)
		{
			cout << mydeq[i] << ' ';
		}
	}
	else
	{
		for(i  = mydeq.size()-1; i >= 0; --i)
		{
			cout << mydeq[i] << ' ';
		}
	}

}	