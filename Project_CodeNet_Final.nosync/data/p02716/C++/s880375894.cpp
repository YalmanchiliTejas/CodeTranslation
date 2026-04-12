#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll ksm(ll a,ll b){ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

const int N=2e5+10;
int n;
ll a[N],f[N],s[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%lld",&a[i]);
	}
	s[1]=a[1];
	for(int i=3;i<=n;i+=2){
		s[i]+=s[i-2]+a[i];
	}
	for(int i=2;i<=n;i++){
		if(i&1){
			f[i]=max(f[i-1],f[i-2]+a[i]);
		}
		else{
			f[i]=max(s[i-1],f[i-2]+a[i]); 
		} 
	}
	printf("%lld",f[n]);
    return 0;
}
