// Author : Sarthak Kapoor
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define rep(i,n) for(int i=0;i<n;++i)
#define repa(i,a,n) for(int i=a;i<n;++i)
#define repr(i,n) for(int i=n-1;i>=0;--i)
#define repba(i,b,a) for(int i=b;i>=a;--i)
#define repab(i,a,b) for(int i=a;i<b;++i)
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define viip vector<pair<int,pair<int,int> > > 
#define mp make_pair
#define vip vector<pair<int,int> >
#define pb push_back 
#define fi first
#define sec second
#define all(v) v.begin(),v.end()
#define s(v) v.size()
ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//use rng()%n for numbers in range [0,n-1]
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
ll fastexp(ll x,ll a){
    ll res = 1;
    while(a>0){
        if(a&1){
            res = (res*x)%mod;
        }
        a=a>>1;
        x=(x*x)%mod;
    }
    return res;
}
ll inverse(ll n){
    return fastexp(n,mod-2);
}
template <typename T>
void add(T &a, T b){
	a += b;
	if(a >= mod)a -= mod;
}
template <typename T>
void sub(T &a, T b){
	a -= b;
	if(a < 0)a += mod;
}
template <typename T>
void mul(T &a, T b){
	a *= b;
	if(a > mod)a %= mod;
}
ll dp[101][2];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// #ifndef ONLINE_JUDGE
 //    	freopen("input.txt", "r", stdin);
 //    	freopen("output.txt", "w", stdout);
	// #endif
	int d;
	string s;
	cin>>s;
	cin>>d;
	int n = s(s);
	dp[0][0] = 1;
	rep(i,n){
		ll temp[d][2];
		rep(j,d){
			rep(k,2)temp[j][k] = 0;
		}
		rep(j,d){
			rep(k,2){
				rep(di,10){
					if(di > s[i]-'0'){
						if(k){
							add(temp[j][k],dp[(j-di+10*d)%d][k]);
						}
					}
					else if(di == s[i]-'0'){
						add(temp[j][k],dp[(j-di+10*d)%d][k]);
						// add()
					}
					else{
						add(temp[j][1],dp[(j-di+10*d)%d][k]);
					}
				}
			}
		}
		rep(j,d){
			rep(k,2){
				dp[j][k] = temp[j][k];
			}	
		}
	}
	ll ans = 0;
	rep(i,2){
		add(ans,dp[0][i]);
	}
	sub(ans,1ll);
	cout<<ans;
	return 0;
}