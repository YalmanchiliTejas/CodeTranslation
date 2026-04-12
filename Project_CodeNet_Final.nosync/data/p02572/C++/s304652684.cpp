#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	ll N;
	cin>>N;
	ll ar[N];
	ll sum=0;
	ll ans=0;

	for(ll i=0;i<N;i++){
		cin>>ar[i];
		sum+=ar[i];
	}
	for(ll i=0;i<N;i++){
		sum-=ar[i];
		ans+=((sum)%MOD*ar[i]);
		ans%=MOD;
	}
	cout<<ans<<endl;
}