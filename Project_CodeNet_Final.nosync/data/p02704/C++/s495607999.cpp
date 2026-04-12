#pragma region Macros
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vecpll vector<pll>
#define vec2(a,b) vector<vec>(a,vec(b))
#define vec2ll(a,b) vector<vecll>(a,vecll(b))
#define vec3(a,b,c) vector<vector<vec>>(a,vec2(b,c))
#define vec3ll(a,b,c) vector<vector<vecll>>(a,vec2ll(b,c))
#define fi first
#define se second
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),(x)))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),(x)))
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {unsigned long long x;cin>>x;return x;}
string stin() {string s;cin>>s;return s;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
vec iota(int n){vec a(n);iota(all(a),0);return a;}
void print(){putchar(' ');}
void print(bool a){cout<<a;}
void print(int a){cout<<a;}
void print(long long a){cout<<a;}
void print(char a){cout<<a;}
void print(string &a){cout<<a;}
void print(double a){cout<<a;}
template<class T> void print(const vector<T>&);
template<class T, size_t size> void print(const array<T, size>&);
template<class T, class L> void print(const pair<T, L>& p);
template<class T, size_t size> void print(const T (&)[size]);
template<class T> void print(const vector<T>& a){ for(auto &e:a){print(e);cout<<" ";}cout<<endl;}
template<class T> void print(const vector<vector<T>>& a){for(auto &e:a){print(e);}}
template<class T> void print(const deque<T>& a){ for(auto &e:a){print(e);cout<<" ";}cout<<endl;}
template<class T, size_t size> void print(const array<T, size>& a){ for(auto &e:a){print(e);cout<<" ";}cout<<endl;}
template<class T, class L> void print(const pair<T, L>& p){ cout<<'(';print(p.first); cout<<","; print(p.second);cout<<')'; }
template<class T, size_t size> void print(const T (&a)[size]){ print(a[0]); for(auto i = a; ++i != end(a); ){ cout<<" "; print(*i); } }
template<class T> void print(const T& a){ cout << a; }
int out(){ putchar('\n'); return 0; }
template<class T> int out(const T& t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
vector<pll> factor(ll x){ vector<pll> ans; for(ll i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
vector<int> divisor(int x){ vector<int> ans; for(int i=1;i*i<=x;i++)if(x%i==0){ans.pb(i);if(i*i!=x)ans.pb(x/i);} return ans;}
int popcount(ll x){return __builtin_popcountll(x);}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n){return uniform_int_distribution<int>(0, n)(rng);}
// #define _GLIBCXX_DEBU
#define endl '\n'
#ifdef _MY_DEBUG
    #undef endl
    #define debug(x) cout<<#x<<": "<<x<<endl
    void err(){}
    template<class T> void err(const T& t){ print(t);  cout<<" ";}
    template<class Head, class... Tail> void err(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); }
#else
    #define debug(x)
    template<class... T> void err(const T&...){}
#endif
#pragma endregion

using ul = unsigned long long ;


vec s,t;
int n;
ul ans[510][510];
bool valid(vec x,vec y,vector<vec> &mp){
    rep(i,n){
        int m = mp[i][0];
        if(s[i])rep(j,n)m|=mp[i][j];
        else rep(j,n)m&=mp[i][j];
        if(m!=x[i])return false;
    }
    rep(j,n){
        int m = mp[0][j];
        if(t[j])rep(i,n)m|=mp[i][j];
        else rep(i,n)m&=mp[i][j];
        if(m!=y[j])return false;
    }
    return true;
}
bool solve(vec x,vec y,ul k){
    auto mp = vector<vec>(n,vec(n,-1));
    rep(i,n)rep(j,n){
        if(x[i]^s[i])mp[i][j]=x[i];
        if(y[j]^t[j]){
            if((mp[i][j]^y[j])==1)return false;
            mp[i][j] = y[j];
        }
    }
    int cx=0,cy = 0;
    rep(i,n)cx+=x[i]^s[i];
    rep(i,n)cy+=y[i]^t[i];
    cx = n-cx, cy = n-cy;
    if(cx==0 or cy==0){
        if(!valid(x,y,mp))return false;
    }
    else if(cx > 1 and cy > 1){
        int cnt = 0;
        rep(i,n){
            if(!(x[i]^s[i])){
                int p = cnt++;
                rep(j,n){
                    if(!(y[j]^t[j]))mp[i][j] = p&1, p++;
                }
            }
        }
    }
    else if(cx==1 and cy==1){
        int tx,ty;
        rep(i,n)if(!(x[i]^s[i]))tx = i;
        rep(i,n)if(!(y[i]^t[i]))ty = i;
        rep(id,2){
            mp[tx][ty]=id;
            if(valid(x,y,mp))break;
            if(id==1)return false;
        }
    }
    else if(cx == 1){
        int c[2]={};
        rep(i,n)if(x[i]^s[i])c[x[i]]++;
        if(c[0] and c[1]){
            rep(i,n)rep(j,n)if(mp[i][j]==-1)mp[i][j]=(i+j)&1;
        }
        else{
            bool flag=false;
            rep(i,n)rep(j,n){
                if(mp[i][j]==-1){
                    if(t[j]){
                        if(c[1]) mp[i][j] = x[i];
                        else mp[i][j] = 1;
                    }
                    else{
                        if(c[0]) mp[i][j] = x[i];
                        else mp[i][j] = 0 ;
                    }
                }
            }
        }
        if(!valid(x,y,mp))return false;
    }
    else if(cy == 1){
        int c[2] = {};
        rep(i,n) if(y[i]^t[i])c[y[i]]++;
        if(c[0] and c[1]) {
            rep(i,n)rep(j,n)if(mp[i][j]==-1)mp[i][j] = (i+j)&1;
        }
        else{
            bool flag = false;
            rep(i,n)rep(j,n){
                if(mp[i][j]==-1){
                    if(s[i]){
                        if(c[1]) mp[i][j] = y[j];
                        else mp[i][j] = 1;
                    }
                    else{
                        if(c[0]) mp[i][j] = y[j];
                        else mp[i][j] = 0;
                    }
                }
            }
        }
        if(!valid(x,y,mp))return false;
    }
    if(!valid(x,y,mp))return false;
    rep(i,n)rep(j,n)ans[i][j] += k*mp[i][j];
    return true;
}


    


signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    n = in();
    vector<ul> u,v;
    rep(i,n)s.pb(in());
    rep(i,n)t.pb(in());
    rep(i,n){ul x;cin>>x;u.pb(x);}
    rep(i,n){ul x;cin>>x;v.pb(x);}
    ul one = 1;
    rep(_,64){
        vec x,y;
        rep(i,n)x.pb(u[i]&1), y.pb(v[i]&1);
        for(auto &e:u)e>>=1;
        for(auto &e:v)e>>=1;
        if(!solve(x,y,one<<_)){
            cout<<-1<<endl;
            return 0;
        }
    }
    rep(i,n){
        rep(j,n){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
}
            
