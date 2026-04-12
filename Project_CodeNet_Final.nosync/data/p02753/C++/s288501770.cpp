#include<bits/stdc++.h>
#define ll long long int
#define fl(i,x,y) for( int i=x;i<y;i++)
#define w(t) while(t--)
#define vi vector<ll>
#define vvi vector< vi >
#define si set<ll>
#define msi multiset<ll>
#define si_d set<ll, greater<ll> >
#define mii map<ll,ll>
#define pb push_back
#define msi_it  multiset<ll> :: iterator
#define si_it set<ll> :: iterator
#define sort1(v) sort(v.begin(),v.end());
#define F first
#define S second
using namespace std;
#define N 1000000007
#define mod 15000000000031
int main()
{
	string s;cin>>s;
	int a=0,b=0;
	fl(i,0,3)
	{
		if(s[i]=='A') a++;
		else b++;
	}
	if(a==0 || b==0) cout<<"No";
	else cout<<"Yes";
}