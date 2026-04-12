#include<bits/stdc++.h>
#define int long long 
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
s.find_by_order(x) xth element in set
x.order_of_key(x) number of elements <x*/
#define ll long long
#define vi vector<int>
#define si set<int>
#define mii map<int,int>
#define pb push_back
#define pf push_front
#define PI acos(-1)
#define pii pair<int,int>
#define extract_word(s)  stringstream str(s); while(str>>word)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SET(s) cout<<fixed<<setprecision(s)
#define set0(a) memset(a,0,sizeof(a))
#define endl "\n"
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define lower_string(s) transform(all(s),s.begin(),::tolower())
#define upper_string(s) transform(all(s),s.begin(),::toupper())
#define size(s) (int)s.size()
template<typename T,typename U>
bool compare(T x,U y){return(abs(x-y)<=1e-9);}
const int MOD=1e9+7;
void solve()
{
fastio
int n,x,m;
cin>>n>>x>>m;
mii mp;
int last=x;
mp[last]=1;
vi v;
v.pb(last);
for(int i=2;i<=n;i++)
{
	last=(last*last)%m;
	if(mp[last])
	{
		int sum=0;
		int init=mp[last];
		for(int k=0;k<init-1;k++)
		{
			sum+=v[k];
		}
		int segment=i-init;
		int rem=n-(init-1);
		int grp=rem/segment;
		int grp_sum=0;
		for(int k=init-1;k<i-1;k++)
		grp_sum+=v[k];
		sum+=grp_sum*grp;
		int beg=init-1;
		for(int i=1;i<=(rem%segment);i++,beg++)
		sum+=v[beg];
		cout<<sum;
		return ;
	}
	else
	{
		mp[last]=i;
		v.pb(last);
	}
}
//10000000000 10 99959
int sum=0;
for(auto &x:v)
sum+=x;
cout<<sum;
}
signed main()
{
//code
fastio
int t;
t=1;
while(t--)
{
solve();
cout<<endl;
}
}
