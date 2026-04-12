#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define inf 100000000
#define mod 1000000007
#define ld long double
#define point complex<long double>
#define pi  acos(-1)
#define IO                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
using namespace std;
int main(){
int n;
cin>>n;
ll arr[n+1];
for(int i=1;i<=n;i++)
{
	cin>>arr[i];
}
vector<int>vec;
vector<int>::iterator it;
for(int i=1;i<=n;i++)
{
	ll cur=arr[i];
	if(vec.size()==0)
	{
		vec.push_back(cur);
		continue;
	}
	it=lower_bound(vec.begin(),vec.end(),cur);
	if(it==vec.begin())
	{
		vec.insert(vec.begin(),cur);
	}
	else 
	{
		it--;
		*it=cur;
	}
	
}
cout<<vec.size()<<endl;
    return 0;
}
