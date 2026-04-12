#include<bits/stdc++.h>

#define Rushia_mywife ios::sync_with_stdio(0);cin.tie(0);
#define rep(i,head,n) for(int i=(head);i<n;i++)
#define F first
#define S second
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define all(x) (x).begin(),(x).end()
#define SZ(x) (int)(x).size()
#define mem(x,i) memset((x),(i),sizeof((x)))
#define odd(x) ((x)&1)
#define LG(x) (int)log2((x))

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<long long,long long>;
using ld = long double;

mt19937 mt_rand(time(0));
const int mod = 1000000007;
const int hnum = 998244353;
const ld PI = acos(-1);

#define int long long
int qpow(int x,int powcnt,int tomod){
	int res = 1;
	for(;powcnt;powcnt>>=1,x=(x*x)%tomod)
		if(1&powcnt)res = (res*x)%tomod;
	return (res%tomod);
}
int gcd(int aaa,int bbb){
	return (bbb==0 ? aaa : gcd(bbb,aaa%bbb));
}
int lcm(int aaa,int bbb){
	return (aaa/gcd(aaa,bbb))*bbb;
}
int C(int x){
	return x*(x-1)/2;
}
// --------------------------------------**

int n,x,m;

void solve(){
	cin >> n >> x >> m;
	vector<int>cir;
	set<int>s;
	int ans = x;
	int sum = 0;
	while(1&&cir.size()<n){
		x = x*x%m;
		if(s.count(x))
			break;
		cir.pb(x);
		s.insert(x);
		sum += x;
	}
	int len = SZ(cir);
	ans += sum;
	n -= len;
	n--;
	int pos = -1;
	rep(i,0,len){
		if(cir[i]==x){
			pos = i;
			break;
		}
		sum -= cir[i];
	}
	int len2 = len-pos;
	int div = n/len2;
	ans += div*sum;
	n -= len2*div;
	rep(i,0,n)
		ans += cir[pos+i];
	cout << ans << '\n';
}

signed main(){
    Rushia_mywife
    //int t; cin >> t;
    //while(t--)
    solve();
}
