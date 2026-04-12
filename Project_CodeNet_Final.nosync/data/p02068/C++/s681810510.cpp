#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
ll mygcd(ll a,ll b){
	if(b==0ll)return a;
	return mygcd(b,a%b);
}
int N;
ll A[100100];
vector<ll> ps;
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> A[i];
		if(A[i]!=1ll)ps.pb(A[i]);
	}
	for(ll i=2;i*i<=1000000000ll;i++){
		for(int j=0;j<N;j++){
			if(A[j]%i==0ll){
				ps.pb(i);
				break;
			}
		}
	}
	sort(ps.begin(),ps.end());
	ps.erase(unique(ps.begin(),ps.end()),ps.end());
	ll ans = 0ll;
	for(int i=0;i<ps.size();i++){
		ll sum = 0ll;
		for(int j=0;j<N;j++){
			if(A[j]%ps[i]==0ll)sum += A[j];
		}
		ans = max(ans,sum);
	}
	cout << ans << endl;
	return 0;
}


