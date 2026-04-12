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
set<int> s;
int32_t main()
{
	int n=in();int x=in();int m=in();
	vector<int> a;
	a.push_back(x);s.insert(x);
	int cycel=-1;
	for(int i=1;i<n;i++)
	{
		int cur=(a[i-1]*a[i-1])%m;
		if(s.find(cur)!=s.end())
		{
			cycel=cur;break;
		}	
		else a.push_back(cur),s.insert(cur);
	}
	if(cycel==-1)
	{
		int ans=accumulate(all(a),0LL);
		cout<<ans;return 0;
	}
	//cout<<cycel;
	int start=-1,i=0;
	for(i=0;i<a.size();i++)if(a[i]==cycel){start=i;break;}
	assert(start!=-1);
	int en=a.size()-1;
	//cout<<start<<" "<<en<<" ";
	
	int sum=0;for(int i=0;i<start;i++)sum+=a[i];
	int len=(en-start+1);n-=start;//cout<<len<<"\n";
	int full=n/len;
	int rem=n%len;
	//cout<<full<<" "<<rem<<"\n";
	int fulls=accumulate(a.begin()+start,a.begin()+en+1,0LL);fulls*=full;
	int rems=accumulate(a.begin()+start,a.begin()+start+rem,0LL);
	cout<<sum+fulls+rems;
	
	
	
}
