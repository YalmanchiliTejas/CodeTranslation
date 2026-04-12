#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
// increase stack size
#pragma comment(linker, "/STACK:16777216666")

ll mxm() {return LLONG_MIN;}
template<typename... Args>
ll mxm(ll a, Args... args) { return max(a,mxm(args...)); }

ll mnm() {return LLONG_MAX;}
template<typename... Args>
ll mnm(ll a, Args... args) { return min(a,mnm(args...)); }

template<class T> ostream& operator<<(ostream& os,vector<T> V){
	os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";
}
template<class L,class R> ostream& operator<<(ostream& os,pair<L,R> P){
	return os<<"("<<P.first<<","<<P.second<<")";
}

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){
	cout<<name<<" : "<<arg1<<endl;
}
template <typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){
	const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);
}
#else
#define trace(...) 1
#endif

#define ld long double
#define pll pair<ll,ll>
#define ii pair<int,int>
#define vll vector<ll>
#define vii vector<ii>
#define vi vector<int>
#define vpll vector<pll>
#define vld vector<ld>
#define vvld vector<vld>
#define vvi vector<vi>
#define vvll vector<vll>
#define vvpll vector<vpll>
#define vvii vector<vii>
#define I insert
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(x)	x.begin(),x.end()

const int mod=1e9+7;
// 128 bit: __int128
inline int add(int a,int b){a+=b;if(a>=mod)a-=mod;return a;}
inline int sub(int a,int b){a-=b;if(a<0)a+=mod;return a;}
inline int mul(int a,int b){return (a*1ll*b)%mod;}
inline int power(int a,int b){int rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
inline int inv(int a){return power(a,mod-2);}

struct compare{
	bool operator() (const int &a,const int &b) const{
		return a>b;
	}
};


const int N = 2e5 + 10;
map<int, ll> mp[N];
vll v;

// ll rec(ll idx, ll n, ll take){
// 	if(take == 0)
// 		return 0;
// 	if(idx >= n)
// 		return -1e18;
// 	if(2 * take - 1 > n - idx)
// 		return -1e18;
// 	ii p = {idx, take};
// 	if(mp.find(p) != mp.end())
// 		return mp[p];
// 	ll ans = max(v[idx] + rec(idx + 2, n, take - 1), rec(idx + 1, n, take));
// 	return mp[p] = ans;
// }

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	int n;
	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	int take = n / 2;
	for(int i = n - 1; i >= 0; i--){
		int mx = (n - i + 1) / 2;
		if(i == n - 1){
			mp[i][0] = 0;
			mp[i][1] = v[i];
			continue;
		}
		for(ll j = mx; j >= mx - 1; j--){
			ll ans1 = -1e18, ans2 = -1e18;
			if(j == 0)
				ans1 = ans2 = 0;
			else if(j == 1)
				ans1 = v[i], ans2 = mp[i + 1][1];
			else
				ans1 = v[i] + (mp[i + 2].find(j - 1) == mp[i + 2].end() ? -1e18 : mp[i + 2][j - 1]),
				ans2 = (mp[i + 1].find(j) == mp[i + 1].end() ? -1e18 : mp[i + 1][j]);
			mp[i][j] = max(ans1, ans2);
		}

	}
	cout << mp[0][n / 2] << endl;
	// cout << rec(0, n, n / 2) << endl;

	// if(n % 2 == 0){
	// 	cout << max(sum1, sum2) << endl;
	// 	return 0;
	// }
	// for(ll i = n - 1; i >= 0; i--)
	// 	suff[i] = v[i] + (i + 2 < n ? suff[i + 2] : 0);
	// for(ll i = 0; i < n; i++)
	// 	pref[i] = v[i] + (i - 2 >= 0 ? pref[i - 2] : 0);
	// ll mx = 0;
	// for(ll i = 0; i < n; i++){
	// 	if(i + 3 < n)
	// 		mx = max(mx, pref[i] + suff[i + 3]);
	// }
	// mx = max(mx, suff[2]);
	// mx = max(mx, pref[n - 3]);
	// cout << mx << endl;
}