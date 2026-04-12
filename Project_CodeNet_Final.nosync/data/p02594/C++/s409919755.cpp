#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 200005

ll fastpower (ll b , ll p){
    ll k= p%2 ? b : 1 ;
    return p==0 ? 1 : k*(fastpower(b*b,p/2));
}

//int v1[105],v2[105];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t=1;
	//cin>>t;
	while(t--){
		ll n;
		cin>>n;
		if(n<30) cout<<"No\n";
		else cout<<"Yes\n";
	}
}