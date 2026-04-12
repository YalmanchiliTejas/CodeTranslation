//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll a;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	ll x=0,j=100;
	while(cin>>a)
	{
	    x+=a*j;
	    j/=10;
	}
	if(x%4==0)
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}
