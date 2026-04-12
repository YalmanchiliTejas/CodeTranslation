#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;

//定数
const int MOD1=1000000007;
const int MOD2=998244353;
const long double PI=3.1415926535897932;
const long long MAXLL=9223372036854775807;
const long long INF=2305843009213693951;
const int dx[]={0,1,0,-1,1,-1,1,-1};
const int dy[]={1,0,-1,0,1,1,-1,-1};

//省略
#define lint boost::multiprecision::cpp_int;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pll pair<long long,long long>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vvvl vector<vector<vector<long long>>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vs vector<string>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vp vector<pair<long long,long long>>
#define umap unordered_map
#define uset unordered_set
#define Lqueue priority_queue<long long>
#define Squeue priority_queue<long long,vector<long long>,greater<long long>>
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define eb emplace_back

//マクロ
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rbf(a,x) for(auto& a:x)
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s);i<(long long)(n);i++)
#define bitrep(i,s,n) for(long long i=(s);i<(1LL<<(n));i++)
#define bitcheck(bit,i) (bit)&(1LL<<(i))
#define Maxe(x) *max_element((x).begin(),(x).end())
#define Mine(x) *min_element((x).begin(),(x).end())
#define Size(x) ((long long)(x).size())
#define Lin(s) getline(cin,(s))

//Yes,No
void Yes(bool a){cout<<(a?"Yes":"No")<<endl;}
void YES(bool a){cout<<(a?"YES":"NO")<<endl;}

//MAX,MIN
template<class T,class U> auto max(T a,U b){return a>b?a:b;}
template<class T,class U> auto min(T a,U b){return a<b?a:b;}

//最大公約数,最小公倍数
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
long long lcm(long long a,long long b){return a/gcd(a,b)*b;}

//切り上げ除算
long long cutup(long long a,long long b){return (a+b-1)/b;}

//累乗
template<typename t>
constexpr t my_pow(t a,long long b){
    if(b==0)return 1;
    if(a==0)return 0;
    t x=1;
    while(b>0){
        if(b&1LL)x*=a;
        a*=a;
        b>>=1LL;
    }
    return x;
}
#define pow my_pow

//chmin,chmax
template<class T,class U> inline bool chmin(T& a,U b){if(a>b){a=b;return true;}return false;}
template<class T,class U> inline bool chmax(T& a,U b){if(a<b){a=b;return true;}return false;}

//組み合わせ O(r)
template<typename t>
constexpr t nCr(t n,long long r){
    if(r==0)return 1;
    if(n==0)return 0;
    if(n<r)return 0;
    t x=1;
    for(long long i=1;i<=r;i++){
        x*=n-i+1;
        x/=i;
    }
    return x;
}

void vin(auto &a){
    rep(i,Size(a)){
        cin>>a[i];
    }
    return;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    vl A(n);
    vin(A);
    vl S(n,0);
    S[0]=A[0];
    rep(i,n-1){
        S[i+1]=S[i]+A[i+1];
        S[i+1]%=MOD1;
    }
    ll res=0;
    rep(i,n){
        ll a=(S[n-1]-S[i]+MOD1)%MOD1;
        res+=a*A[i];
        res%=MOD1;
    }
    cout<<res<<endl;
}