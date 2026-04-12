//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0)
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
const double pi = acos(-1);
typedef long long ll;
ll arr[1000000];
int main()
{
	fast;
	ll n,s=0,i,m,ans=0;
	m=1000000007;
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		s+=arr[i];
		s%=m;
	}
	for(i=0;i<n;i++)
	{
		s-=arr[i];
		if(s<0)s+=m;
		ans+=(arr[i]*s);
		ans%=m;
	}
	cout<<ans<<endl;
}