/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

int n,x,ans;
multiset <int> st;
multiset <int>::iterator pos;

int main()
{
	cin>>n;
	rep(i,n)
	{
		cin>>x;
		pos=st.lower_bound(-x+1);
		if(pos==st.end()) ans++;
		else st.erase(pos);
		st.insert(-x);
	}
	cout<<ans<<endl;
	return 0;
}