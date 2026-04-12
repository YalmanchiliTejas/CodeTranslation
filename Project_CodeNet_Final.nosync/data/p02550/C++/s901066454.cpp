#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

// static int mi[100000];
// static ll ms[100000];

int main(){
	ll n;
	int x, m;
	cin>>n>>x>>m;

	vector<ll> mi(m, -1);
	vector<ll> ms(m);
	// rep(i, m) mi[i]= -1;

	ms[x]=x;
	mi[x]=1;
	int c=x;
	ll s=x;
	bool skipped=false;
	for(ll i=2; i<=n; i++){
		c=(ll)c*c%m;
		s+=c;
		if(mi[c]!= -1){
			if(!skipped){
				ll len=i-mi[c];
				ll ds= s-ms[c];
				ll b=(n-i)/len;
				s+= ds*b;
				i+= b*len;
				skipped=true;
			}
		}
		else{
			mi[c]=i;
			ms[c]=s;
		}
	}

	cout<<s<<endl;
	return 0;
}
