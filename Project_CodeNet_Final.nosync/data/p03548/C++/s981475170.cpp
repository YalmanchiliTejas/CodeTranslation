#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int l,a,b;
	cin>>l>>a>>b;
	a += b;
	int ans = 0, j = l;
	for(int i = a; i<=l ; i+=a)
	{
		ans++;
		j -= a;
	}
	if(j<b)
		ans--;
	cout<<ans<<endl;
	return 0;
}