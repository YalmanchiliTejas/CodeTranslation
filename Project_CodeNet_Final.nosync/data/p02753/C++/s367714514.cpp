/*    "Whatever sprinkles your donuts" :-) ~amit_dwivedi  */
#include "bits/stdc++.h"
using namespace std;using ll = long long;using ld = long double;
#define _(_1, _2, _3, _4, NAME, ...) NAME
#define f3(i, a, n, inc) for(int i = (a) - (inc < 0); (inc) > 0 ? i < (n) : i >= (n); i += (inc))
#define f2(i, a, n) f3(i, a, n, 1 - 2*(a > n))
#define f1(i, n) f2(i, 0, n)
#define f0(i) f2(i, 0, n)
#define fr(...) _(__VA_ARGS__, f3, f2, f1 , f0)(__VA_ARGS__)
#define trav(i,x) for(auto& i: x)
#define sz(x) ((int)x.size())
#define len(x) ((int)x.length())
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define all(x) begin(x),end(x)
#define lb lower_bound 
#define ub upper_bound
const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos(-1.0);
namespace fastestIO {
    const int BUF_SIZE = 100000;
    bool IOerror = 0;
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if (p1 == pend) {
            p1 = buf; pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p1) {
                IOerror = 1; return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t'; 
    }
    template <typename T>
    
    bool read(T &x){
        bool sign = 0;
        char ch = nc(); x = 0;
        for (; blank(ch); ch = nc());
        if (IOerror) return false;
        if (ch == '-'){

            sign = 1, ch = nc();
        }
        for (; ch >= '0' && ch <= '9'; ch = nc()) 
            x = x * 10 + ch - '0';
        if (ch == '.') {
            T tmp = 1; ch = nc();
            for (; ch >= '0' && ch <= '9'; ch = nc()) tmp /= 10.0, x += tmp * (ch - '0');
        }
        if (sign) 
            x = -x;
        return true;
    }
    bool read(string& x){
        char ch = nc();
        x = "";
        if((ch>='a' && ch <='z') || (ch>='A' && ch<='Z')){
            
            for (;(ch>='a' && ch <='z') || (ch>='A' && ch<='Z') || (ch >='0' && ch <='9'); ch = nc())
                x = x+ch;
            return true;
        }
        return false;
    }
}using namespace fastestIO;

namespace io{
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
    template<class T> void re(T& x) { read(x);}//cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); } 
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class T, class... Ts> void re(T& t, Ts&... ts) { re(t); re(ts...);}
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = {a,b}; }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { fr(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { fr(i,SZ) re(a[i]); }
    void pr(int x) { cout << x; }
    void pr(long x) { cout << x; }
    void pr(ll x) { cout << x; }
    void pr(unsigned x) { cout << x; }
    void pr(unsigned long x) { cout << x; }
    void pr(unsigned long long x) { cout << x; }
    void pr(float x) { cout << x; } void pr(double x) { cout << x; }
    void pr(ld x) { cout << x; }
    void pr(char x) { cout << x; }
    void pr(const char* x) { cout << x; }
    void pr(const string& x) { cout << x; }
    void pr(bool x) { pr(x ? "true" : "false"); }
    template<class T> void pr(const complex<T>& x) { cout << x; }
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T> void pr(const T& x);
    template<class T, class... Ts> void pr(const T& t, const Ts&... ts){pr(t); pr(ts...); }
    template<class T1, class T2> void pr(const pair<T1,T2>& x) { pr("{",x.f,", ",x.s,"}"); }
    template<class T> void pr(const T& x) { pr("{");bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; pr("}");}
    void ps() { pr("\n"); } 
    template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); }
    void pc() { pr("]\n"); } 
    template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); } 
}using namespace io;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 


void solve(){
    string s;
    cin>>s;
    int c1 = 0 , c2 = 0;
    fr(i,3){
        if(s[i] == 'A') c1++;
        else c2++;
    }
    if(c1 and c2) pr("Yes");
    else
        pr("No");
}

int main(){
  // ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
  // int _ = 1;re(_);while (_--)    
  solve();
}

