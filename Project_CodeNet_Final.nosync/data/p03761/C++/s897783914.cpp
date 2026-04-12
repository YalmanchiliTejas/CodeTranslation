#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pll pair<long long,long long>
#define pcc pair<char,char>
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

const int MOD1=1000000007;
const int MOD2=998244353;
const long double PI=3.1415926535897932;
const long long MAXLL=9223372036854775807;
const long long INF=2305843009213693951;
const int dx[]={0,1,0,-1,1,-1,1,-1};
const int dy[]={1,0,-1,0,1,1,-1,-1};

#define unless(a) if(!(a))
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rbf(a,x) for(auto& a:x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(n);i++)
#define bitrep(i,s,n) for(int i=(s);i<(1LL<<(n));i++)
#define bitcheck(bit,i) (bit)&(1LL<<(i))
#define Maxe(x) *max_element((x).begin(),(x).end())
#define Mine(x) *min_element((x).begin(),(x).end())
#define Size(x) ((long long)(x).size())
#define Lin(s) getline(cin,(s))

void Yes(bool a){cout<<(a?"Yes":"No")<<endl;}
void YES(bool a){cout<<(a?"YES":"NO")<<endl;}
template<class T,class U> auto max(T a,U b){return a>b?a:b;}
template<class T,class U> auto min(T a,U b){return a<b?a:b;}
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
long long lcm(long long a,long long b){return a/gcd(a,b)*b;}
long long cutup(long long a,long long b){return (a+b-1)/b;}
long long popcnt(long long a){return __builtin_popcountll(a);}
template<class T,class U> inline bool chmin(T& a,U b){if(a>b){a=b;return true;}return false;}
template<class T,class U> inline bool chmax(T& a,U b){if(a<b){a=b;return true;}return false;}

struct edge{long long to,cost;};
struct edge2{long long from,to,cost;};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vl C(26,INF);
    rep(i,n){
        string s;
        cin>>s;
        rep(j,26)chmin(C[j],count(all(s),char('a'+j)));
    }
    rep(i,26){
        if(C[i]==INF)continue;
        rep(j,C[i]){
            cout<<char('a'+i);
        }
    }
    cout<<endl;
}