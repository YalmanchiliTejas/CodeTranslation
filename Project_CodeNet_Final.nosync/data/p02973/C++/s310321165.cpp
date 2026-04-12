#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,ans=0;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(v.empty())
		{
			v.push_back(x);
			++ans; 
		} 
		else
		{
			if(x<=v[0])
			{
				v.insert(v.begin(),x);
				++ans;
			}
			else
			{
				int tmp=lower_bound(v.begin(),v.end(),x)-v.begin()-1;
				v.erase(v.begin()+tmp);
				v.insert(v.begin()+tmp,x);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}