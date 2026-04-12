#include <bits/stdc++.h>
#define t(w) ll w; cin>>w; while(w--) 
// #define ipv()
typedef long long int ll; 
typedef unsigned long long int ull; 
// __builtin_popcount(n));

using namespace std;

vector<ll> seve(1000001,0);

void create_seve(){
	seve[0]=1;
	seve[1]=1;
    for(ll i=2;i<=1000000;i++){
        for(ll j=2;j*j<=i;j++){
            if(i%j==0){
                seve[i]=1;
                break;
            }
        }
    }
}

bool is_prime(ll n){
    return seve[n];
} 

vector<pair<ll,ll>> prime_factorization(ll n){
	vector<pair<ll,ll>> pf;
	for(ll i=2;i*i<=n;i++){
		ll c=0;
		while(n%i==0){
			c++;
			n/=i;
		}
		if(c!=0)
			pf.push_back(make_pair(i,c));	
	}
	if(n>1)
		pf.push_back(make_pair(n,1));
	return pf;
}

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

ll power(ll a,ll n){
	ll ans=1;
	while(n>0){
		if(n&1){
			ans*=a;
		}
		a*=a;
		n=n>>1; 
	}
	return ans;
}

ll modulo_power(ll a,ll n,ll m){
	ll ans=1;
	while(n>0){
		if(n&1){
			ans=(ans*a)%m;
		}
		a=(a*a)%m;
		n=n>>1; 
	}
	return ans%m;
}

ll sumofdig(ll ds){
	ll ans=0;
	while(ds){
		ans+=ds%10;
		ds=ds/10;	
	}
	return ans;
}

void solve3(){
	ll n;
	cin>>n;
	string s,s1="abacaba";
	cin>>s;
	ll p=0;
	for(ll i=0;i<n-6;i++){
		string a=s.substr(i,7);
		if(a==s1)		
			p++;
	}
	
	if(p==1){
		cout<<"YES"<<endl;
		for(ll i=0;i<n;i++){
			if(s[i]=='?')
				cout<<'d';
			else
				cout<<s[i];
			}
			cout<<endl;
			return;
	}
	if(p>1){
		cout<<"NO"<<endl;
		return;
	}	
	for(ll i=0;i<n-6;i++){
		string a=s.substr(i,7);
		bool f=true;
		string ans="";
		for(ll j=0;j<7;j++){
			if(a[j]==s1[j]){
				ans=ans+s1[j];
			}
			else if(a[j]=='?'){
				ans=ans+s1[j];
			}
			else{
				f=false;
				break;
			}
		}
		if(f){
			cout<<"YES"<<endl;
			for(ll j=0;j<i;j++){
				if(s[j]=='?')
					cout<<'d';
				else
					cout<<s[j];
			}
			cout<<ans;
			for(ll j=i+7;j<n;j++){
				if(s[j]=='?')
					cout<<'d';
				else
					cout<<s[j];
			}
			cout<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}

void solve1(){
	ll n,k,z;
	cin>>n>>k>>z;
	vector<ll> v,p;
	for(ll i=0;i<n;i++){
		ll a;
		cin>>a ;
		v.push_back(a);
	}
	if(z==0){
		ll sum=0;
		cout<<accumulate(v.begin(),v.begin()+k+1,0)<<endl;
		return;
	}
	ll ans;
	for(ll i=1;i<=k;i++){
		p.push_back(v[i-1]+v[i]);
	}
	auto pos=max_element(p.begin(),p.end());
	
	ll ind=pos-p.begin();
//	cout<< ind<<endl;
	
	ans=accumulate(v.begin(),v.begin()+ind+2,0);
//	cout<<"ans"<<ans<<endl;
	k=k-(ind+1);
	bool f=true;
//	cout<<k<<endl;
	ll l=0;
	while(k){
		if(z and f){
			f=false;
			ans=ans+v[ind];
			k--;
			z--;
			l=ind;
			if(z==0)
				break;
		}
		else{
			ans=ans+v[ind+1];
			k--;
			f=true;
			l=ind+1;

		}
	}
//	cout<<"ans"<<ans<<endl;
	while(k){
		l++;
		ans+=v[l];
//		cout<<v[l]<<" ";
		k--;
	}
//	cout<<endl;
	cout<<ans<<endl;
}
 
void solve2(){
	ll a,b,c;
	ll m=1000000007;
	cin>>a>>b>>c;
	ll x=power(a%m,b)%m;
	x%=m;
    ll ans=power(x,c)%m;
	cout<<ans;
}



void solve(){
	ll a;
	cin>>a;
	if(a<30){
		cout<<"No\n";
	}
	else
	{
		 cout<<"Yes\n";
	}
	
}



int main(){
	{
		solve();
	}
	// vector<pair<ll,ll>> a=prime_factorization(36);
	// for(pair<ll,ll> b:a){
	// 	cout<<b.first<<" "<<b.second<<"\n";
	// }
	//cout<<ceil();
	return 0;
}

