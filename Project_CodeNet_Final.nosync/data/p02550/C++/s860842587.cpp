#include<bits/stdc++.h>
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define fi first
#define se second
#define inf 1000000000
#define mod 1000000007
using namespace std;
template <typename T> void chmax(T &x,T y){x=x>y?x:y;return;}
template <typename T> void chmin(T &x,T y){x=x<y?x:y;return;}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

int x,m;
ll n;
vector<ll> v;
int vis[100005];

int main()
{
	cin>>n>>x>>m;
	ll num=x;
	while(vis[num]==0)
	{
		v.pb(num);
		vis[num]=1;
		num*=num;
		num%=m;
	}
	int cnt=0;
	ll sum1=0,sum2=0,sum3=0;
	for(vector<ll>::iterator it=v.begin();it!=v.end();it++)
		if(*it==num)
		{
			for(vector<ll>::iterator it2=v.begin();it2!=it;it2++)
				sum1+=*it2;
			n-=cnt;
			v.erase(v.begin(),it);
			break;
		}else cnt++;
	for(int i=0;i<sz(v);i++)
		sum2+=v[i];
	int rem=n%sz(v);
	for(int i=0;i<sz(v)&&rem>0;i++)
		sum3+=v[i],rem--;
	ll ans=sum1+n/sz(v)*sum2+sum3;
	cout<<ans<<endl;
	return 0;
}