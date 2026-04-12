//vowel と、そうでないとき consonant

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz size()
#define pb(x) push_back(x) 
#define bg begin()
#define ed end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define mp(x,y) make_pair(x,y)
const ll MOD=1000000007;
const ll INF=1000000000000000;

vector<ll> pw2(51,1); vector<ll> pw10(19,1);
ll maxx(ll x,ll y,ll z){return max(max(x,y),z);}
ll minn(ll x,ll y,ll z){return min(min(x,y),z);}
ll mid(ll x,ll y,ll z){return x>y?y>=z?y:min(z,x):x>=z?x:min(y,z);}
ll gcd(ll x,ll y){if(x%y==0) return y;else return gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
ll myceil(ll x,ll y){if(x<=y) return 1;else if(x%y==0) return x/y;else return x/y+1;}
vector<ll> divisor(ll x){
	vector<ll> div;
	for(int i=1;i*i<=x;i++){
		if(i*i!=x && x%i==0){
			div.pb(i);
			div.pb(x/i);
		}
		else if(x%i==0) div.pb(i);
	}
	return div;
}
vector<ll> vectorprime(ll x){
	vector<bool> is_prime(x+1);
	vector<ll> prime;
	rep(i,x+1) is_prime[i]=true;
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i<=x;i++){
		if(is_prime[i]){
			prime.pb(i);
		}
		for(int j=i*2;j<=x;j+=i) is_prime[j]=false;
	}
	return prime;
}

//a,b x
int main(){
	string s; cin>>s;
	if(s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u'){
		cout<<"vowel";
	}
	else cout<<"consonant";
		
	
}