#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	ll ans2 = (n/15)*200;
	ll ans = (n)*800;
	cout<<ans-ans2<<endl;
	return 0;
}