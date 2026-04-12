
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long 
#define ull unsigned long long
#define db double
#define vi vector<ll>
#define vvi vector<vector<int> >
#define vvii vector<vector<pii> >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define endl "\n"
#define pii pair<ll,ll>
#define piii pair<ll,pair<ll,ll> >
#define mem(a,b) memset(a , b , sizeof a ) ; 
#define pb push_back
#define pf push_front
#define F first 
#define S second 
#define mp make_pair
#define all(v) v.begin(),v.end()

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}



#define deb1(a) cout<<#a<<"=*"<<a<<endl;
#define deb2(a) cout<<#a<<"=@"<<a<<endl;
#define deb3(a) cout<<#a<<"=#"<<a<<endl;
#define deb4(a,b) cout<<#a<<"="<<a<<" and "<<#b<<"="<<b<<endl;
#define deb5(a,b) cout<<#a<<"="<<a<<" and "<<#b<<"="<<b<<endl;


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


ll mod=1000000007;
ll vis[212345]={0};
vvi v(212345);
ll d[212345]={0};


ll pow(ll a, ll b, ll m)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}





int main()
{
speed
ll x;
cin>>x;
if(x>=30) cout<<"Yes\n";
else cout<<"No\n";
}

