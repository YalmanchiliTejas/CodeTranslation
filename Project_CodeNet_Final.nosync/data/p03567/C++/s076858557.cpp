#include <bits/stdc++.h>
#define fast_cin() ios_base::sync_with_stdio(0) 
typedef long long int ll;
using namespace std;
const int MOD=1e9+7;
const int size=1e5+5;

ll a[size],b[size];

int main()
{
	ll n;
	string s;
	cin >> s;
	string x="AC";
	for(int i=0;i<s.length()-1;i++)
	{
		string y=s.substr(i,2);
		//cout << x << " " << y << endl;
		if(x==y)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";

}
