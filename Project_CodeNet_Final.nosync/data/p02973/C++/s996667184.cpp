#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int32_t main()
{
	int n=in();
	vector<int> a(n);
	for(int i=0;i<n;i++)
	a[i]=in();
	multiset<int> s;
	reverse(all(a));
	s.insert(a[0]);int x;
	for(int i=1;i<n;i++)
	{
		x=a[i];
		auto it=s.upper_bound(x);
		if(it==s.end())s.insert(x);
		else
		{
			s.insert(x);s.erase(it);
		}
	}
	cout<<s.size();
}