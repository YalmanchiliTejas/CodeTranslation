#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<int> a[n];
	for(int i = 0,j,k;i<m; i++)
	{
		cin>>j>>k , --j,--k;
		a[k].push_back(j);
		a[j].push_back(k);
	}
	if(n==2)
	{
		cout<<1<<endl;
		return 0;
	}
	vector<int> v(n-1);
	iota(v.begin(),v.end(),1);
	int count = 0;
	int fact = 1;
	for(int i = 1;i<n;i++)
		fact *= i;
	int ans = 0;
	while(count<fact)
	{
		count++;
		if(find(a[0].begin(),a[0].end(),v[0])!=a[0].end())
		for(int i = 1; i<n-1; i++)
		{
			if(find(a[v[i]].begin(),a[v[i]].end(),v[i-1])==a[v[i]].end())
				break;
			else if(i==n-2)
				ans++;
		}
		next_permutation(v.begin(),v.end());
	}
	cout<<ans<<endl;
	return 0;
}