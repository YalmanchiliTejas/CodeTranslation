#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define vec vector<ll>
#define ms multiset<ll>
#define f(i,x,n) for(int i=x;i<n;i++)
#define int long long
#define mod 998244353
#define endl "\n"
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
multiset<int>se;
int32_t main()
{
    fastio();
    int n;
    cin>>n;
    int a[n];
    f(i,0,n)
    {
    	cin>>a[i];
    }
    int ans=1;
    se.insert(a[0]);
    for(int i=1;i<n;i++)
    {
    	auto aa=se.lower_bound(a[i]);
    	if(aa==se.begin())
    	{
    		ans++;
    		se.insert(a[i]);
    		continue;
    	}
    	aa--;
    	se.erase(aa);
    	se.insert(a[i]);
    }
    cout<<ans;
}