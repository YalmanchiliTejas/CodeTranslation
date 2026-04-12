#include<bits/stdc++.h>
using namespace std;
    
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
    
#define int long long
#define double long double
    
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (int)x.size()
    
#define ff first
#define ss second
#define mp make_pair
         
#define pb push_back
#define endl "\n" 
         
#define f(i,l,r) for(int i=l;i<=r;i++)
#define rf(i,r,l) for(int i=r;i>=l;i--)    

#define bp __builtin_popcountll
#define inf 3e15
    
const int N=2e5+5;
const int M=1e9+7;
void solve()
{
	int n;
	cin>>n;
	multiset<int> s;
	int a[n];
	int ans=0;
	f(i,0,n-1){
		cin>>a[i];
		if(s.size()==0)
		{
			s.insert(a[i]);
			ans++;
		}
		else
		{
			auto it=s.lower_bound(a[i]);
			if(it==s.begin())
			{
				ans++;
				s.insert(a[i]);
			}
			else
			{
				it--;
				s.erase(it);
				s.insert(a[i]);
			}
		}
	}
	cout<<ans;
}
signed main()  
{
	FAST
    int t=1;
    // cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
    	// cout<<"Case #"<<tc<<": ";
    	solve();
    }
}

