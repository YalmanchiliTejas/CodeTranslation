#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define db double
#define pb push_back
#define nl '\n'
#define X first
#define Y second
#define nimble ios::sync_with_stdio(0);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define mod(x,m) ((((x)%(m))+(m))%(m))
#define _sz(x) (int)x.size()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repv(v) for(int i=0;i<_sz(v);i++)
#define rep1(i,b,a) for(int i=b;i>=a;i--)
#define preci(x) fixed<<setprecision(x)
#define tc int tt=1;cin>>tt;rep(tcs,1,tt+1)

#define TRACE
#ifdef TRACE
#define see(...) __f(#__VA_ARGS__,__VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr<<name<<" : "<<arg1<<nl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma=strchr(names+1,',');cerr.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1, args...);
}
#else
#endif

int inf=0x3f3f3f3f;
ll infl=0x3f3f3f3f3f3f3f3fLL;
ld infd=1.0/0.0;
const ll MOD=1e9+7;// 998244353 // = (119<<23)+1
const ld pi=2*acos(0.0);

int main(){
    nimble
    int x;
    cin>>x;
    if(x>=30){
        cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}
