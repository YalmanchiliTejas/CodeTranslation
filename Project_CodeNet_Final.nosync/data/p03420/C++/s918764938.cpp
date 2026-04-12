#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
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
vector<ll> divisor(ll x){vector<ll> div;
	for(int i=1;i*i<=x;i++){if(i*i!=x && x%i==0){div.pb(i);div.pb(x/i);}else if(x%i==0) div.pb(i);}
	sort(div.bg,div.ed);return div;}
vector<ll> vectorprime(ll x){vector<bool> is_prime(x+1);vector<ll> prime;
	rep(i,x+1) is_prime[i]=true;is_prime[0]=is_prime[1]=false;
	for(int i=2;i<=x;i++){if(is_prime[i]){prime.pb(i);}for(int j=i*2;j<=x;j+=i) is_prime[j]=false;}
	return prime;}
ll digsz(ll x){if(x==0) return 1;else{ll ans=0;while(x){x/=10;ans++;}return ans;}}
ll digsum(ll x){ll sum=0;while(x){sum+=x%10;x/=10;}return sum;}

//a,b x
int main(){
	//rep1(i,50) pw2[i]=2*pw2[i-1];
	//rep1(i,18) pw10[i]=10*pw10[i-1];
    ll N,K; cin>>N>>K;
	ll ans=0;
	for(int b=K+1;b<=N;b++){
		ans+=((N+1)/b)*(b-K);//周期分
		ans+=max(0ll,(N+1)%b-K);
		if(K==0) ans--;//0
	}
	cout<<ans;
}