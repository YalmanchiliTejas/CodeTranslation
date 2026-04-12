#include<bits/stdc++.h>
#define ll long long
#define all(v) v.begin(),v.end()
#define rall(v) v.begin(),v.end()
#define sz(x) (int)x.size()
#define PB push_back
#define PI 3.1415926535897932384626433832795
#define what(x) cout<<#x<<" is "<<x<<endl;
using namespace std;

#ifdef LOCAL//ONLINE_JUDGE
#include "D:\c_c++\template.h"
#else
#define debug(...) 42
#endif

ll powmod(ll a,ll b,ll mod) {
    ll res=1;a%=mod;
    for(;b;b>>=1){
        if(b&1)res=res*a%mod;
			a=a*a%mod;
    }
    return res;
}
vector<ll> vp;
unordered_set<ll> st;
void solve(){
	ll n,x,m;
	cin>>n>>x>>m;
	ll i=1;
	vp.push_back(x);
	st.insert(x);
	while(i<=n){
		x=(x*x)%m;
		if(st.find(x)!=st.end()){
			ll sum=0,cnt=0;
			ll ind=i;
			for(int j=sz(vp)-1;j>=0;j--){
				cnt++;
				sum+=vp[j];
				if(vp[j]==x)break;
			}
			//....(repeating)
			//tot-sz(vp)  repeating  = cnt its sum 
			ll temp = sz(vp)-cnt,s=0;
			for(int j=0;j<temp;j++)s+=vp[j];
			n-=temp;
			s+=(n/cnt)*sum;
			n%=cnt;
			for(int j=temp,k=0;k<n;j++,k++){
				s+=vp[j];
			}
			cout<<s<<'\n';
			return;
		}
		st.insert(x);
		vp.push_back(x);
		i++;
	}
	ll sum=0;
	for(int i=0;i<n;i++){
		sum+=vp[i];
	}
	cout<<sum<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//    #ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
    int tc=1;
    // cin>>tc;
    while(tc--)solve();
}
