#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const ll LINF = 0x1fffffffffffffff;
#define name3(_1,_2,_3,name,...) name
#define rep1(n) for(ll i=0;i<(n);++i)
#define rep2(i,n) for(ll i=0;i<(n);++i)
#define rep3(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(...) name3(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep(i,a,b) for(ll i=(b)-1;i>=(a);i--)
#define each(i,a) for(auto &i : a)
#define sum(a) accumulate(all(a), 0LL)
#define all(i) begin(i), end(i)
template<class T, class U> inline bool chmin(T &a, const U &b){ if(a > b) { a = b; return 1; } else return 0; }
template<class T, class U> inline bool chmax(T &a, const U &b){ if(a < b) { a = b; return 1; } else return 0; }


int main(){
    string s, t;
    cin >> s >> t;
    ll n=t.size(),m=s.size();
    vector<ll>a(n);
    ll at=-1;
    rep(n){
        at++;
        while(at<m&&s[at]!=t[i])at++;
        if(at==m)return!puts("no");
        a[i]=at;
    }
    reverse(all(s));
    reverse(all(t));
    at=-1;
    rep(n){
        at++;
        while(at<m&&s[at]!=t[i])at++;
        if(a[n-1-i]!=m-1-at)return!puts("no");
    }
    puts("yes");
}

