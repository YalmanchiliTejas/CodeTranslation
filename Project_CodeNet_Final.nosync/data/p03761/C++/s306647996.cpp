#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<pdd> vdd;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mem(a,b) memset(a, b, sizeof(a) )
#define all(x) (x).begin(),(x).end()
#define INF 1000000000000
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){
    int n;cin>>n;
    vector<string>s(n);
    vector<pair<int,char>> a;
    int l=51;
    string t;
    rep(i,n){
        cin>>s[i];
        int x=s[i].size();
        if(l>x){
            l=x;
            t=s[i];
        }
        sort(s[i].begin(),s[i].end());
    }
    sort(all(t));
    char c=t[0];
    int cnt=1;
    for(int i=1;i<l;++i){
        if(c==t[i]){
            cnt++;
        }
        else{
            a.PB(MP(cnt,c));
            cnt=1;
            c=t[i];
        }
    }
    a.PB(MP(cnt,c));
    int m=a.size();
    rep(i,n){
        int x=s[i].size();
        rep(j,m){
            int co=0;
            rep(k,x){
                if(s[i][k]==a[j].S){
                    co++;
                }
            }
            if(co<a[j].F){
                a[j].F=co;
            }
        }
    }
    string ans="";
    rep(i,m){
        rep(j,a[i].F){
            ans.PB(a[i].S);
        }
    }
    cout<<ans<<endl;
}