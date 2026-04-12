#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define rev(x) x.rbegin(), x.rend()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define endl '\n'
#define pi 3.141592653589793238
#define mp make_pair
#define pb push_back
#define precise cout<<fixed<<setprecision(20)
#define ff first
#define ss second
#define T int t;cin>>t;rep(mmm,0,t)
#define watch(x) cerr<<(#x)<<" is "<<(x)<<endl;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;

const int N=100001;
int mod=1000000007;
//mod=998244353;

int min(int a,int b){if(a<b) return a; else return b;}
int max(int a,int b){if(a>b) return a; else return b;}
int power(int a,int b){int res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int gcd(int p, int q){if(p%q==0) return q; else{return gcd(q,p%q);}} 
int mul(int a,int b){return ((a%mod)*(b%mod))%mod;}
int sub(int a,int b){return (((a-b)%mod)+mod)%mod;}

void solve()
{
	int n;
	cin>>n;
	int sum=0;
	int sq=0;
	rep(i,0,n)
	{
		int a;
		cin>>a;
		sum+=a;
		sum%=mod;
		sq+=mul(a,a);
	}
	cout<<mul(sub(mul(sum,sum),sq),power(2,mod-2));
}

signed main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}