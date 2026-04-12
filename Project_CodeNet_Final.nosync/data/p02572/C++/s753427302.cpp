#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back
#define mp make_pair
#define F first
#define S second 
#define pl pair<long long ,long long >
#define pi pair<int ,int >
#define lb(v,x) lower_bound(v.begin(),v.end(),x)-v.begin()
#define ub(v,x) upper_bound(v.begin(),v.end(),x)-v.begin()
#define ct(i) cout<< i << "\n"
#define sv(v) sort(v.begin(),v.end())
#define mod 1000000007
#define M 100005
#define endl "\n"

void solve(){
    ll n,x=0,ans=0;
    string s,t;
    cin>>n;
    ll a[n],suf[n];
	for(int i=1;i<n+1;i++){
		cin>>a[i-1];
	}
	suf[n-1]=0;
	for(int i=n-2;i>=0;i--)
		suf[i]=(a[i+1]+suf[i+1])%mod;
	for(int i=0;i<n;i++){
		ll va=a[i];
		va=(va*suf[i])%mod;
		ans=(ans+va)%mod;
	}
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int q;
    //cin>>q; while(q--)
        solve();
    return 0;
}
