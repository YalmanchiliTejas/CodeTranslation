#include <bits/stdc++.h>
using namespace std;
long long n,x,ans=0;
vector<long long> a,pt;
int main(){
	long long i,pos;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	for(i=0;i<n;i++)
	{
		pos=lower_bound(pt.begin(),pt.end(),a[i])-pt.begin();
		if(pos==0)
		{
			pt.insert(pt.begin(),a[i]);
		}
		else
		{
			pt[pos-1]=a[i];
		}
	}
	cout<<pt.size()<<endl;
	return 0;
}