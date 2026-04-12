// --------------------<optimizations>--------------------
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)\
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)\
#pragma GCC optimize("unroll-loops")

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair<ll,ll>
#define vpii vector<pair<ll,ll> >
#define F first
#define S second
#define ld long double
#define built __builtin_popcountll
#define mst(a,i) memset(a,i,sizeof(a))
#define all(x) x.begin(),x.end()
#define itit(it,a) for(auto it=(a).begin(); it!=(a).end(); it++)
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define repr(i,a,b) for(ll i=a; i>b; i--)
#define reprr(i,a,b) for(ll i=a; i>=b; i--)
#define pi 3.14159265358979323846264338327950288419716939937510582097494459230
ll max3(ll x,ll y,ll z) {return max(max(x,y),z);}
ll min3(ll x,ll y,ll z) {return min(min(x,y),z);}
const ll N=1e5+10,M=2e5+10,M2=1e6+10,mod=1e9+7,inf=1e17+10;
const int INF=1e9+7;
void add(int& a, int b) {a+=b;if(a>=mod){a-=mod;}}

#define trace(...) cerr<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cerr<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    const char *comma=strchr(names+1,',');
    cerr.write(names,comma-names)<<" : "<<arg1<<" | ";
    __f(comma+1,args...);
}

int X[] = {0, 1, 0, -1};
int Y[] = {-1, 0, 1, 0};
//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
ll power(ll x,ll n){ll result=1;while(n>0){if(n%2==1)result=(result*x)%mod; x=((x%mod)*(x%mod))%mod;n=n/2;}return result;}

string n;
int k;
int sz;
int x[105];

int cache[105][5][2];

int dp(int idx, int cnt, int less){
    if(cnt>k) return 0;
    if(idx==sz+1){
        return (cnt==k);
    }
    int &ans=cache[idx][cnt][less];
    if(ans!=-1) return ans;
    ans=0;
    if(!less){
        for(int i=0; i<=x[idx]; i++){
            if(i!=0) ans+=dp(idx+1, cnt+1, less|(i<x[idx]));
            else ans+=dp(idx+1, cnt, less|(i<x[idx]));
            ans%=mod;
        }
    }
    else{
        for(int i=0; i<=9; i++){
            if(i!=0) ans+=dp(idx+1, cnt+1, less);
            else ans+=dp(idx+1, cnt, less);
            ans%=mod;
        }
    }
    return ans;
}

int f(string &s){
    sz=s.size();
    for(int i=0; i<sz; i++) x[i+1]=s[i]-'0';
    mst(cache,-1);
    return dp(1,0,0);
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> k;
    int res=f(n);
    //trace(f(n));
    //rep(i,1,sz+1) cout << x[i] << "\n";
    res%=mod;
    cout << res;
    return 0;
}