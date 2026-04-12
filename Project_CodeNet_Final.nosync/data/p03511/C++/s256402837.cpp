#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int dp[411111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int L; cin>>L;
	string s,t;
	cin>>s>>t;
	dp[0] = 1;
	for(int i=1;i<=L;i++)
	{
		if(i>=s.length()) dp[i]|=dp[i-s.length()];
		if(i>=t.length()) dp[i]|=dp[i-t.length()];
	}
	if(s.length()>t.length()) swap(s,t);
	bool ispref=1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!=t[i])
		{
			ispref=0; break;
		}
	}
	if(!ispref)
	{
		if(s>t) swap(s,t);
	}
	else
	{
		string t2=t+t;
		for(int i=0;i<t2.length();i++)
		{
			if(s[i%int(s.length())]!=t2[i])
			{
				if(s[i%int(s.length())]>t2[i])
				{
					swap(s,t); 
				}
				break;
			}
		}
	}
	string cur="";
	while(cur.length()<L)
	{
		int l = cur.length();
		if(l+int(s.length())<=L)
		{
			if(dp[L-l-int(s.length())])
			{
				cur+=s;
				continue;
			}
		}
		cur+=t;
	}
	cout<<cur<<'\n';
}	
