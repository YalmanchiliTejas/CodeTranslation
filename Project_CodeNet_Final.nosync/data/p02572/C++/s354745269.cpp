#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
vector <ll> input;
ll prefix[200005];

ll M = 1000000007;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	ll i,j,k,l,m,n,x,y,z,a,b,c;
 
	cin >> n;

	for(i=0;i<n;i++)
	{
		cin >> k;
		input.push_back(k);
	}

	prefix[0] = input[0];

	for(i=1;i<n;i++)
	{
		prefix[i] = prefix[i-1]%M+input[i]%M;
		prefix[i] = prefix[i]%M;
	}

	ll ans = 0;

	for(i=0;i<n-1;i++)
	{
		ans = ans+(input[i]%M)*((prefix[n-1]-prefix[i]+M)%M);
		ans = ans%M;
	}

	cout << ans << '\n';


 
}