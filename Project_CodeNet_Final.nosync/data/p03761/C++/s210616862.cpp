#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define MOD (ll)(1e9+7)
#define INF 1e17
#define int ll
#define EPS (1e-6)
using namespace std;
using ll=long long;
using pii=pair<int,int>;

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }

int fpow(int b,int p)
{
	if(p==0) return 1;
	int h=fpow(b,p/2);
	if(p%2) return h*b%MOD*h%MOD;
	return h*h%MOD;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin>>n;
	string s; cin>>s;
	sort(all(s));
	string t;
	For(lkjhakjshdfg,1,n-1){
		cin>>t;
		sort(all(t));
		int i=0,j=0;
		string ans="";
		while(i<sz(s) && j<sz(t)){
			if(s[i]==t[j]){
				ans+=s[i];
				i++; j++;
			}
			else if(s[i]>t[j]) j++;
			else i++;
		}
		s=ans;
	}
	if(sz(s)>0) cout<<s<<"\n";
	return 0;
}



























