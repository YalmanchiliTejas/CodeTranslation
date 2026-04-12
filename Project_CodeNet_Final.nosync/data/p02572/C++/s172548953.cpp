#include<bits/stdc++.h>
using namespace std;
	
	#define 	ll 						long long int
	#define 	REP(i,a,b)				for(i=a;i<=b;i++)
	#define 	REPr(i,b,a)				for(i=b;i>=a;i--)
	#define 	pb 						push_back
    #define 	mp 						make_pair
    #define 	f  						first
   	#define 	s  						second
   	#define 	umap(type1,type2)		unordered_map<type1,type2>

ll mod = pow(10,9)+7;

void solve(){
	ll n;	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)	cin>>arr[i];
	ll sum=0;
	ll ans=0;
	for(ll i=n-1;i>0;i--){
		sum=(sum+arr[i])%mod;
		ans=(ans+(sum*arr[i-1]))%mod;
	}

	cout<<ans<<endl;
}

void pb_18(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	/***************************

		FuCk RATINGS I am in love with EXPERIENCE.

	***************************/

	int t;	t=1;
	while(t--)	solve();
}

int main(){
	pb_18();
}