#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define repin(a,n) vector<ll> a(n);rep(i,n){cin>>a[i];}
#define repins(a,n) vector<string> a(n);rep(i,n){cin>>a[i];}
#define repind(a,n) vector<double> a(n);rep(i,n){cin>>a[i];}
#define in(a) ll a;cin>>a;
#define ins(a) string a;cin>>a;
#define ind(a) double a;cin>>a;
template<class T>
inline void out(T a){cout<<a<<endl; }
inline void out(double a){ printf("%.10f\n", a);} 
#define all(x) (x).begin(),(x).end()
#define rep2(i,a,b) for(ll i=(a);i<(b);++i)
using vell = vector<ll>;
using ves = vector<string>;
using ved = vector<double>;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int main()
{
	ins(s);
	if(s[0]==s[1]&&s[1]==s[2]){
		out("No");
	}else{
		out("Yes");
	}
}