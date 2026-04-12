/*
	---------O7Oo7oO7O-------------
*/

#include <bits/stdc++.h>

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
#define all(v) v.begin(),v.end()

const int mod = 1000*1000*1000 +7;
int Bin_expo(int n, int b)
{
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
		{
			res = (res * n) % mod;

		}
		n = (n * n)  % mod;


		b /= 2;

	}
	return res % mod;
}


int32_t main()
{
	IOS


	

	int n;
	cin>>n;
	vector<int> v(n);
	vector<int> suf(n,0),pref(n);
	int p = 0;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		
		if(i==0)
			pref[i] = v[i];
		else
			pref[i] = pref[i-1] +v[i];
		

	}

	suf[n-1] = v[n-1];
	for(int i=n-2;i>=0;i--)
	{
		suf[i] = (suf[i+1] + v[i]) % mod;
	}

	for(int i=0;i<n-1;i++)
	{
		p += (v[i] * suf[i+1]) % mod;
		p%=mod;
		if(p<0)
			p+=mod;
	}

	cout<<p<<"\n";
}


