#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define MP make_pair
#define vi vector<int>
#define pb push_back
using namespace std;
const int N=1e5+5;
int n,x[N];
vi v;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<n;i++)
	{
		int l=lower_bound(v.begin(),v.end(),x[i])-v.begin();
		if(l==0)
			v.insert(v.begin(),x[i]);
		else
			v[l-1]=x[i];
	}
	cout<<v.size()<<endl;
	return 0;
}