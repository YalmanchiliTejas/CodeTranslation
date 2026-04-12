#include <bits/stdc++.h>
using namespace std;

//定数
const long long MOD1=1000000007;
const long long MOD2=998244353;
const long double PI=3.1415926535897932;
const long long MAXLL=9223372036854775807;
const long long INF=2305843009213693951;
const long long dx[]={0,1,0,-1,1,-1,1,-1};
const long long dy[]={1,0,-1,0,1,1,-1,-1};

//型名省略
#define ll long long
#define ull unsigned long long
#define ld long double
#define uld unsigned long double
#define pll pair<long long,long long>
#define tll(n) array<long long,(int)(n)>
#define pcc pair<char,char>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vp vector<pair<long long,long long>>
#define vt(n) vector<array<long long,(int)(n)>>
#define umap unordered_map
#define uset unordered_set
#define Lqueue priority_queue<long long>
#define Squeue priority_queue<long long,vector<long long>,greater<long long>>
#define Fi first
#define Se second
#define mp make_pair
#define eb emplace_back

//マクロ
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rbf(a,x) for(auto& a:x)
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s);i<(long long)(n);i++)
#define bitrep(i,s,n) for(long long i=(s);i<(1LL<<(n));i++)
#define Maxe(x) *max_element((x).begin(),(x).end())
#define Mine(x) *min_element((x).begin(),(x).end())
#define Size(x) ((long long)(x).size())
#define lin(s) getline(cin,(s))
#define Ssort(v) sort((v).begin(),(v).end(),[](auto &left,auto &right){return left.second<right.second;})

//Yes,No
void Yes(bool a){cout<<(a?"Yes":"No")<<endl;}
//YES.NO
void YES(bool a){cout<<(a?"YES":"NO")<<endl;}

//MAX,MIN
template<class T,class U> auto max(T a,U b){return a>b?a:b;}
template<class T,class U> auto min(T a,U b){return a<b?a:b;}

//最大公約数,最小公倍数
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
long long lcm(long long a,long long b){return a/gcd(a,b)*b;}

//累乗
template<typename t>
constexpr t mypow(t a,long long b){
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
#define pow mypow

//chmin,chmax
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

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

//main関数
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    cout<<n*800-n/15*200<<endl;
}