#include<bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

#define Debug(x) cout<<(#x)<<" >> "<<(x)<<endl

using namespace std;

ll fastpow(ll angka,ll pangkat,ll MOD){
	ll res=1;
	while(pangkat){
		if(pangkat&1) res=(res*angka)%MOD;
		angka=(angka*angka)%MOD;
		pangkat=pangkat>>1;
	}
	return res;
}

ll fastpow(ll angka,ll pangkat){
	ll res=1;
	while(pangkat){
		if(pangkat&1) res=(res*angka);
		angka=(angka*angka);
		pangkat=pangkat>>1;
	}
	return res;
}

ll gcd(ll angka1,ll angka2){
	while(angka2){
		swap(angka1,angka2);
		angka2=angka2%angka1;
	}
	return angka1;
}

ll lcm(ll angka1,ll angka2){
	return (angka1/gcd(angka1,angka2))*angka2;
}



void solve(){
	int x;
	cin>>x;
	
	if(x>=30) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}

int main(){
	
	fastio();
	
	int t=1;
//	cin>>t;
	
	for(int tt=0;tt<t;tt++){
//		cout<<"Case #"<<tt+1<<": ";solve();
//		if(solve()) cout<<""<<endl;
		solve();
	}
	
	return 0;
}


