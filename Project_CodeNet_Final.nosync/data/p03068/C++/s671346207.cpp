#include <bits/stdc++.h>
using namespace std;

//入力
template<typename T>
istream& operator>>(istream& is,vector<T>& a){
    for(int i=0;i<a.size();i++)is>>a[i];
    return is;
}
template<typename T,typename U>
istream& operator>>(istream& is,pair<T,U>& p){
    is>>p.first>>p.second;
    return is;
}

//出力
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a){
    for(int i=0;i<a.size();i++){
        os<<a[i]<<((i+1!=a.size())?" ":"");
    }
    return os;
}
template<typename T,typename U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
    os<<p.first<<" "<<p.second;
    return os;
}

//入出力高速化
struct hishimochi{
    hishimochi(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout<<fixed<<setprecision(10);
    }
};
hishimochi Hishimochi;

//辺
struct edge{
    long long to,cost;
    edge(long long t,long long c):to(t),cost(c){}
};
struct edge2{
    long long from,to,cost;
    edge2(long long f,long long t,long long c):from(f),to(t),cost(c){}
};

//型名
using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pll=pair<long long,long long>;
using vl=vector<long long>;
using vvl=vector<vector<long long>>;
using vvvl=vector<vector<vector<long long>>>;
using vc=vector<char>;
using vvc=vector<vector<char>>;
using vs=vector<string>;
using vb=vector<bool>;
using vvb=vector<vector<bool>>;
using vp=vector<pair<long long,long long>>;
using Lqueue=priority_queue<long long>;
using Squeue=priority_queue<long long,vector<long long>,greater<long long>>;

//定数
const int MOD1=1000000007;
const int MOD2=998244353;
const long double PI=3.1415926535897932;
const long long MAXLL=9223372036854775807;
const long long INF=2305843009213693951;
const long double eps=0.000000001;
const int dx[]={0,1,0,-1,1,-1,1,-1};
const int dy[]={1,0,-1,0,1,1,-1,-1};

//マクロ
#define overload3(_1,_2,_3,name,...) name
#define rep1(n) for(int _=0;_<(n);_++)
#define rep2(i,n) for(int i=0;i<(n);i++)
#define rep3(i,s,n) for(long long i=(s);i<(n);i++)
#define rep(...) overload3(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define bitrep1(n) for(int _=0;_<(1LL<<(n));_++)
#define bitrep2(i,n) for(int i=0;i<(1LL<<(n));i++)
#define bitrep3(i,s,n) for(int i=(s);i<(1LL<<(n));i++)
#define bitrep(...) overload3(__VA_ARGS__,bitrep3,bitrep2,bitrep1)(__VA_ARGS__)
#define rrep0(n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep2(i,s,n) for(long long i=(n-1);i>=(s);i--)
#define rrep(...) overload3(__VA_ARGS__,rrep2,rrep1,rrep0)(__VA_ARGS__)
#define rbf(a,x) for(auto& a:x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define bitcheck(bit,i) (bit)&(1LL<<(i))
#define Maxe(x) *max_element((x).begin(),(x).end())
#define Mine(x) *min_element((x).begin(),(x).end())
#define Sume(x) accumulate((x).begin(),(x).end(),0LL)
#define Size(x) ((long long)(x).size())
#define Sort(x) sort((x).begin(),(x).end())
#define rSort(x) sort((x).rbegin(),(x).rend())
#define Rev(x) reverse((x).begin(),(x).end())
#define Lin(s) getline(cin,(s))

//省略
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define eb emplace_back

//関数
void Yes(bool a){cout<<(a?"Yes":"No")<<endl;}
void YES(bool a){cout<<(a?"YES":"NO")<<endl;}
long long modpow(long long x,long long n,int m){long long r=1;while(n>0){if(n&1)(r*=x)%=m;(x*=x)%=m;n>>=1;}return r;}
long long Gcd(long long a,long long b){return b?Gcd(b,a%b):a;}
long long Lcm(long long a,long long b){return a/Gcd(a,b)*b;}
inline long long cutup(long long a,long long b){return (a+b-1)/b;}
inline long long popcnt(long long a){return __builtin_popcountll(a);}
template<class T,class U> auto max(T a,U b){return a>b?a:b;}
template<class T,class U> auto min(T a,U b){return a<b?a:b;}
template<class T,class U> inline bool chmin(T& a,U b){if(a>b){a=b;return true;}return false;}
template<class T,class U> inline bool chmax(T& a,U b){if(a<b){a=b;return true;}return false;}
template<class T> void print(T a){cout<<a<<endl;}
template<class t> t mypow(t a,long long b){if(b==0)return 1;if(a==0)return 0;t x=1;while(b>0){if(b&1LL)x*=a;a*=a;b>>=1LL;}return x;}

signed main(){
    ll n,k;
    string s;
    cin>>n>>s>>k;
    k--;
    rep(i,n){
        if(s[i]!=s[k])s[i]='*';
    }
    print(s);
}