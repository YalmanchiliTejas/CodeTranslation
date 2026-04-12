#include <bits/stdc++.h>
using namespace std;

#define sc(a) scanf("%d",&a)
#define scm(a,b) scanf("%d%d",&a,&b)
#define fl(c,i,n) for(int i=c;i<n;i++)
#define f(i,n) for(int i=0;i<n;i++)
#define mem(a) memset(a,0,sizeof(a))
#define ll long long int
#define ull unsigned long long int
#define inf INT_MAX
#define linf LLONG_MAX
#define pb push_back
#define pp pop_back()
#define aov(a) a.begin(),a.end()
//#define mp make_pair
#define nl printf("\n")
#define PI 2.0*acos(0.0) //#define PI acos(-1.0)
#define xx first
#define yy second
#define mxv(a) *max_element(aov(a))
#define mnv(a) *min_element(aov(a))
#define LB(a,x) (lower_bound(aov(a),x)-a.begin())
#define UB(a,x) (upper_bound(aov(a),x)-a.begin())
#define to_c_string(a) a.c_str()
#define strtoint(c) atoi(&c[0])
#define pii pair<int,int>
#define MAXN 500005
#define MOD 1000000007

template <class T> inline T bigmod(T p,T e,T M){
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
/*int fact[MAXN];
int invfact[MAXN];
int inv(int a, int b){
    if(b==0)
        return 1;
    if(b&1)
        return (long long)a*inv(a, b-1)%MOD;
    else{
        int res = inv(a, b>>1);
        return (long long)res*res%MOD;
    }
}
void init(){
    fact[0] = 1;
    for(int i=1;i<MAXN;i++){
        fact[i] = (long long)fact[i-1]*i%MOD;
    }
    invfact[MAXN-1] = inv(fact[MAXN-1], MOD-2);
    for(int i=MAXN-1;i>0;i--){
        invfact[i-1] = (long long)invfact[i]*i%MOD;
    }
}
int C(int n, int r){
    if(r>n || r<0)
        return 0;
    return (long long)((long long)fact[n]*invfact[r]%MOD)*invfact[n-r]%MOD;
}*/
int n;
map<char, int> mp;
string alph = "abcdefghijklmnopqrstuvwxyz", s;
void solve(){
    sc(n);
    for(int i=0;i<26;i++){
        mp[alph[i]] = 100;
    }
    for(int t=0;t<n;t++){
        map<char, int> tmp;
        cin>>s;
        for(int j=0;j<s.length();j++){
            tmp[s[j]]++;
        }
        for(int j=0;j<26;j++){
            mp[alph[j]] = min(mp[alph[j]], tmp[alph[j]]);
        }
    }
    string ans = "";
    for(int i=0;i<26;i++){
        for(int j=0;j<mp[alph[i]];j++){
            ans+=alph[i];
        }
    }
    cout<<ans;
}
int main(){
    /*FILE *fin = freopen("C-small-attempt0.in", "r", stdin);
	assert( fin!=NULL );
	FILE *fout = freopen("C-small.out", "w", stdout);*/
	//init();
    solve();
    return 0;
}
