#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	// ll t;   cin>>t;
	// for(ll tt = 1; tt <= t; tt++)
	// {
	//     //Code
	    
	// }
	ll n;	cin>>n;
	if(n >= 30)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
