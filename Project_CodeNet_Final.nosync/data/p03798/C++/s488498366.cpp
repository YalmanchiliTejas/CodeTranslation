#include <bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define ITR(i,x) for(auto i=(x).begin();i!=(x).end();++i)
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int, int> P;
typedef long long ll;
const ll mod = 1000000007;

ll mpow(ll x, ll n){ //x^n(mod) ←普通にpow(x,n)では溢れてしまうため，随時mod計算 2分累乗法だから早い
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % mod;
        x = x*x % mod;
        n = n >> 1;
    }
    return ans;
}
ll inv_mod(ll a){return mpow(a,mod-2);}
bool square(ll a){ll n=(ll)sqrt(a);return a==n*n;}
int digitsum(ll N,int a){
    if(N==0) return 0;
    int ret=0;
    ret+=digitsum(N/a,a)+N%a;
    return ret;
}
int gcd(int x,int y){return y ? gcd(y,x%y) : x;};//xとyの最大公約数
int lcm(int x,int y){return x*y/gcd(x,y);}//xとyの最小公倍数
vector<ll> splitint(string n,int a){
    int Len=n.length();
    if(a<0||Len<a) return {-1,-1};
    string left,right;
    if(a!=0) left=n.substr(0,a);
    if(a!=Len) right=n.substr(a);
    return {stoll(left),stoll(right)};
}
template<ll mod> class mint {
 private:
  ll _num;
  mint set(ll num){ _num = num % mod; return *this; }
 public:
  mint(){ _num = 0; }
  mint(ll num){ _num = num % mod; }
  mint(const mint &cp){_num=cp._num;}
  mint operator= (ll x){ return set(x % mod); }
  mint operator+ (ll x){ return mint<mod>(_num + (x % mod)); }
  mint operator- (ll x){ return mint<mod>(_num - (x % mod)); }
  mint operator* (ll x){ return mint<mod>(_num * (x % mod)); }
  mint operator/ (ll x){ return mint<mod>(_num * inv_mod(x));}
  mint operator+=(ll x){ return set(_num + (x % mod)); }
  mint operator-=(ll x){ return set(_num - (x % mod)); }
  mint operator*=(ll x){ return set(_num * (x % mod)); }
  mint operator/=(ll x){ return set(_num * inv_mod(x));}
  mint operator+ (mint x){ return mint<mod>(_num + x._num ); }
  mint operator- (mint x){ return mint<mod>(_num - x._num);}
  mint operator* (mint x){ return mint<mod>(_num * x._num); }
  mint operator/ (mint x){ return mint<mod>(_num * inv_mod(x._num));}
  mint operator+=(mint x){ return set(_num + x._num); }
  mint operator-=(mint x){ return set(_num - x._num); }
  mint operator*=(mint x){ return set(_num * x._num); }
  mint operator/=(mint x){ return set(_num * inv_mod(x._num));}

  friend mint operator+(ll x,mint m){return mint<mod>(m._num + (x % mod));}
  friend mint operator-(ll x,mint m){return mint<mod>(m._num - (x % mod));}
  friend mint operator*(ll x,mint m){return mint<mod>(m._num * (x % mod));}
  friend mint operator/(ll x,mint m){return mint<mod>(inv_mod(m._num) * x);}

  explicit operator ll() { return _num; }
  explicit operator int() { return _num; }

  friend ostream& operator<<(ostream &os, const mint<mod> &x){ os << x._num; return os; }
  friend istream& operator>>(istream &is, mint<mod> &x){int val; is>>val; x.set(val); return is;}
};
class UnionFind{//UnionFind木
 private:
    vector<int> Parent;
 public:
    UnionFind(int N){
        Parent.resize(N);
        REP(i,N) Parent[i]=-1;
    }

    int root(int A){
        if(Parent[A]<0) return A;
        else return Parent[A]=root(Parent[A]);
    }

    int size(int A){
        return -Parent[root(A)];
    }

    bool connect(int A,int B){
        A=root(A); B=root(B);
        if(A==B) return false;
        if(size(A)<size(B)) swap(A,B);
        Parent[A]+=Parent[B];
        Parent[B]=A;
    }
};
class Factorial{//階乗とその逆元を求めて計算に利用するクラス
 private:
    vector<ll> fac;
 public:
    
    Factorial(ll N){
        fac.push_back(1);
        for(int i=0;i<N;i++) fac.push_back(fac[i]*(i+1)%mod);
    }

    ll fact(ll a){return fac[a];}
    ll ifact(ll a){return inv_mod(fac[a]);}

    ll cmb(ll a,ll b){
        if(a==0&&b==0) return 1;
        if(a<b||a<0) return 0;
        ll tmp =ifact(a-b)*ifact(b)%mod;
        return tmp*fac[a]%mod;
    }
};
struct Solutions{
    ll napsack(int kinds,int MAX_W,vector<ll> weight,vector<ll> cost){
        vector<vector<ll>> dp(kinds+1,vector<ll>(MAX_W+1,0));
        REP(i,kinds) REP(j,MAX_W+1){
            if(j<weight[i]) dp[i+1][j]=dp[i][j];
            else dp[i+1][j]=max(dp[i][j],dp[i][j-weight[i]]+cost[i]);
        }
        return dp[kinds][MAX_W];
    }
    ll unlimited_napsack(int kinds,int MAX_W,vector<ll> weight,vector<ll> cost){
        vector<vector<ll>> dp(kinds+1,vector<ll>(MAX_W+1,0));
        REP(i,kinds) REP(j,MAX_W+1){
            if(j<weight[i]) dp[i+1][j]=dp[i][j];
            else dp[i+1][j]=max(dp[i][j],dp[i+1][j-weight[i]]+cost[i]);
        }
        return dp[kinds][MAX_W];
    }
    ll Partition_Func(int n,int k){
        vector<vector<ll>> dp(k+1,vector<ll> (n+1,0));
        dp[0][0]=1;
        rep(i,1,k+1) REP(j,n+1){
            if(j-i>=0) dp[i][j]=(dp[i][j-i]+dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
        return dp[k][n];
    }
    int LCS(string s,string t){
        int n=s.length(),m=s.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        REP(i,n) REP(j,m){
            if (s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
        return dp[n][m];
    }
    int LIS(vector<ll> a){
        int n=a.size();
        ll INF=1<<28;
        vector<ll> dp(n+1,INF);
        REP(i,n) *lower_bound(All(dp),a[i])=a[i];
        int k=lower_bound(All(dp),INF)-dp.begin();
        return k;
    }
};

int main(){
    ll N;
    cin>>N;
    string s;
    cin>>s;
    char pattern[2]={'S','W'};
    REP(j,2) REP(k,2){
        string ans="";
        ans.push_back(pattern[j]);
        ans.push_back(pattern[k]);
        rep(i,1,N){
            if(ans.back()=='S'){    
                if(s[i]=='o') ans.push_back(ans[i-1]);
                else ans.push_back(ans[i-1]=='S'?'W':'S');
            }
            else if(ans.back()=='W'){
                if(s[i]=='x') ans.push_back(ans[i-1]);
                else ans.push_back(ans[i-1]=='S'?'W':'S');
            }
        }
        if(ans[0]=='S'){
            if(s[0]=='o'&&ans[N-1]!=ans[1]) continue;
            if(s[0]=='x'&&ans[N-1]==ans[1]) continue; 
        }
        else if(ans[0]=='W'){
            if(s[0]=='x'&&ans[N-1]!=ans[1]) continue;
            if(s[0]=='o'&&ans[N-1]==ans[1]) continue;
        }
        if(ans[0]==ans[N]){
            ans.pop_back();
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
