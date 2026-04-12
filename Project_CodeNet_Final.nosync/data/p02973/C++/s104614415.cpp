#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	//freopen("input.txt", "r", stdin);
	
	int n; cin>>n;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	vector<int > non_inc;
	non_inc.push_back(a[n-1]);
	
	for(int i=n-2; i>=0; i--)
	{
		if(a[i] >= non_inc.back())
			non_inc.push_back(a[i]);
		else if(a[i]<non_inc[0])
			non_inc[0] = a[i];
		else
		{
			auto it = upper_bound(non_inc.begin(), non_inc.end(), a[i]);
			*it = a[i];
		}
	}
	cout<<(int) non_inc.size();
}