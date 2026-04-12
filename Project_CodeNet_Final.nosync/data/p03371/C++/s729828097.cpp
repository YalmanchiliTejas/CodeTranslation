#include<bits/stdc++.h>
#define ll long long int 
#define w(x) int x; cin>>x; while(x--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
int main(){
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	ll z=min(x,y);
	ll ab=c*z*2;
	if(x>y)
		ab+=(x-y)*a;
	else
		ab+=(y-x)*b;
	ll m=a*x+b*y;
	ll n=c*2*(max(x,y));
	cout<<min(m,min(n,ab));
	

}