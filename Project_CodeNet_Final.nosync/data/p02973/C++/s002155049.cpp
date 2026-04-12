#include <bits/stdc++.h>
using namespace std;
#define ll          long long int
#define pll         pair<ll,ll>
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mod         1000000007
#define F           first
#define S           second
#define vl          vector<ll>
#define ld          long double
#define fix(n)      cout<<fixed<<setprecision(n)
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define pi          3.14159265358979323

const int N = 2e5+5;
ll can[N];
ll a[N];

void solve()
{
       ll n; cin>>n;
       rep(i,1,n+1) cin>>a[i];
       ll ans=0;
       multiset<ll>m;
       rep(i,1,n+1)
       {
              multiset<ll>::iterator it = m.lower_bound(a[i]);
              if(it==m.begin()) m.insert(a[i]);
              else
              {
                     it--;
                     m.erase(it);
                     m.insert(a[i]);
              }
       }
       ans=m.size();
       cout<<ans<<endl;
}

int main(){
	int T = 1;
       //pre();
	speed_up
	//cin>>T;
	while(T--)
	    solve();
	return 0;
}
