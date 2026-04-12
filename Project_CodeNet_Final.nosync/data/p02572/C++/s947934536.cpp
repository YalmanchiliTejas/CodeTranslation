#include<bits/stdc++.h>
using namespace std;
const long long INF = 1000000007;
int main()
{
	int n;
	long long ans=0;
	cin>>n;
	vector<int> a(n);
	for(int& x:a)
	cin>>x;
	long long ss=0;
	for(int i=0;i<n;i++)
	{
		ans= (ans+(long long)a[i]*ss)%INF;
		//cout<<ans<<" ";
		ss=(ss+a[i])%INF;
		//cout<<ss<<endl;
	}
	cout<<ans;
	return 0;
}
