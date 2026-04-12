#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store") // to restrict undesirable precision
#pragma GCC optimize ("-fno-defer-pop")// to pop argument of function as soon as it returns
#define all(a) a.begin(),a.end()
#define ll long long int
#define ld long double
ll power(ll a,ll b,ll m){ if(b==0) return 1; if(b==1) return a%m; ll t=power(a,b/2,m)%m; t=(t*t)%m; if(b&1) t=((t%m)*(a%m))%m; return t;}
ll modInverse(ll a, ll m) { return power(a, m-2, m); }
#define ps push_back
#define fs first
#define takeline cin.ignore();
#define sc second
#define N 3000005
#define endl "\n"
#define mod 1000000007
//((1.0l)*BIG MULTIPLY MAGIC?)
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
//-----------------------------------------------
int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll i,j,k,l,n;
	cin>>n;
	ll ar[n+1];
	for(i=1;i<=n;i++){
		cin>>ar[i];
	}
	ll an=1,mx=1;
	set< pair<ll,ll> > st;
	st.insert({ar[1],1});
	for(i=2;i<=n;i++){
		set<pair<ll,ll>>:: iterator it=st.upper_bound(make_pair(ar[i],0));
		if(it==st.begin()){
		//	cout<<ar[i]<<" 1 "<<(*it)<<endl;
			mx++;
			st.insert({ar[i],mx});
			continue;
		}
		it--;
		st.insert({ar[i],it->sc});
		set<pair<ll,ll>>:: iterator i2=it;
		st.erase(i2);
	}
	cout<<mx;
	return 0;
}