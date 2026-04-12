#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define S(x) (int)(x).size()
#define L(x) (int)(x).length()
#define ld long double
#define mem(x,y) memset(x,y,sizeof x)

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int , null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_set;

const int mod = 1e9+7;
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;

int state[100009];
void solve()
{
	ll n,x,m;
	cin>>n>>x>>m;
	ll ans=0;
	vector<int> v;
	int len=0;
	mem(state,-1);
	while(state[x]==-1 && n)
	{
		state[x]=len;
		v.pb(x);
		ans+=x;
		x=x*x%m;
		n--;
		len++;
	}
	ll temp=0;
	for(int i=state[x];i<len;i++) temp+=v[i];
	len = len-state[x];
	//cout<<temp<<'\n';
	ans+=temp*(n/len);
	n%=len;
	for(int i=0;i<n;i++) ans+=v[state[x]+i];
	cout<<ans<<'\n';
}
//12722645
//9999998970
//9999999756
//492443256176507
int main()
{
	IOS
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
}
