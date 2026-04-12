#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll m = 998244353;
ll n,s;

vector<ll> a;
vector<vector<ll>> dph;
vector<vector<ll>> dpf;

ll h(int x, int s){
	if (s<0||x<0){
		return 0;
	}
	if (dph[x][s]!=-1){return dph[x][s];}
	return dph[x][s]=((h(x-1,s-a[x])+h(x-1,s))+((a[x]==s)?(1):0))%m;;
}

ll f(int x, int s){
	if (s<0||x<0){
		return 0;
	}
	if (dpf[x][s]!=-1){return dpf[x][s];}
	return dpf[x][s]=(f(x-1,s-a[x])+f(x-1,s)+((a[x]==s)?(x+1):0))%m;
}

int main(){
	cin>>n>>s;
	a.resize(n);
	for (int i = 0; i<n; i++){
		cin>>a[i];
	}
	dph.resize(n,vector<ll>(s+1,-1));
	dpf.resize(n,vector<ll>(s+1,-1));
	//h(n-1,s);
	f(n-1,s);
	ll sum = 0;
	for (int i = 0; i<n; i++){
		sum+=f(i,s);
		//cout<<h(i,s)<<endl;
		sum%=m;
	}
	cout<<sum<<endl;
}