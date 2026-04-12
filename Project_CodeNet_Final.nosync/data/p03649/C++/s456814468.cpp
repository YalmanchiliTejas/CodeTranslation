#include <bits/stdc++.h>
using namespace std;

#define int long long int

const int mod = 998244353;

#undef int
int main()
{
#define int long long int
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++)
		cin>>v[i];
	int ans = 0;
	while(1)
	{
		bool done = true;
		for(int i = 0;i<n;i++)
		{
			if(v[i] >= n)
			{
				int inc = v[i]/n;
				v[i]%=n;
				ans += inc;
				for(int j = 0;j<n;j++)
					if(i!=j)
						v[j]+=inc;
				if(inc)
					done = false;
			}
		}
		if(done)
			break;
	}
	cout<<ans<<endl;

	return 0;
}