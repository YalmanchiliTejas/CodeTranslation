#include<bits/stdc++.h>
#define MAX 5002
#define pb push_back
#define For(i,s,e) for (ll i=(s); i<(e); i++)
#define Debug_array(a,n) for (ll i=(0); i<(n); i++) cout<<a[i]<<" "
#define Foe(i,s,e) for (ll i=(s); i<=(e); i++)
#define Fod(i,s,e) for (ll i=(s)-1; i>=(e); i--)
#define Mod 1000000007
#define pii pair<ll,ll>
#define fi first
#define se second
#define pf push_front
#define endl "\n"
#define mp make_pair

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	
	ll n;cin>>n;
	ll a[n];
	For(i,0,n) cin>>a[i];
	ll b[n];For(i,0,n) b[i]=a[i];
	sort(b,b+n);
	deque<ll> q1,q2;
	
	ll s = 1,e=n-1;
	bool toggle=1;
	q1.pb(b[0]);
	while(s<=e){
		if(toggle){
			q1.pb(b[e--]);
			if(s>e) break;
			q1.pf(b[e--]);
		}else{
			q1.pb(b[s++]);
			if(s>e) break;
			q1.pf(b[s++]);
		}
		toggle = !toggle;
	}

	s = 0,e=n-2;
	q2.pb(b[n-1]);
	toggle=1; 
	while(s<=e){
		if(toggle){
			q2.pb(b[s++]);
			if(s>e) break;
			q2.pf(b[s++]);
		}else{
			q2.pb(b[e--]);
			if(s>e) break;
			q2.pf(b[e--]);
		}
		toggle = !toggle;
	}
	vector<ll> ans1,ans2;
	deque <ll> :: iterator it; 
    for (it = q1.begin(); it != q1.end(); ++it) ans1.pb(*it);
    for (it = q2.begin(); it != q2.end(); ++it) ans2.pb(*it);

    ll a1 = 0,a2=0;
	For(i,1,n){a1 += abs(ans1[i]-ans1[i-1]);}
	For(i,1,n){a2 += abs(ans2[i]-ans2[i-1]);}

	cout<<max(a1,a2)<<endl;

}