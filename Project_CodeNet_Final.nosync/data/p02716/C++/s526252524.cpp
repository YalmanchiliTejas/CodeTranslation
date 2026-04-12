#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define REP(i,a,n) for(int i=a;i<n;++i)
#define REPR(i,a,n) for(int i=a;i>n;--i)
#define RUP(a,b) (((a)+(b)-1)/(b))
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define INF LLONG_MAX/2
#define PI acos(-1.0)
//#define MOD 1000000007

typedef long long ll;
typedef pair<int,int> Pii;
typedef tuple<int,int,int> Tiii;
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef vector<Pii> VPii;
typedef vector<string> Vs;
typedef priority_queue<int> PQi;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
void vout(Vi &v){for(int i=0;i<(v).size();i++) cout<<v[i]<<" ";cout<<endl;}
void vout(Vs &v){for(int i=0;i<(v).size();i++) cout<<v[i]<<" ";cout<<endl;}
void vvout(VVi &v){for(int i=0;i<(v).size();i++) vout(v[i]);}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
int mypow(int x, int n, int m){if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}
int digit(int k,int i){string s = to_string(k);return s[s.size()-i]-'0';}
void uniq(Vi &v){sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());} //vectorの同じ要素消す
int ctoi(char c){if(c>='0'&&c<='9'){return c-'0';}return 0;}
int leng(int n){string s=to_string(n); return s.size();} //intの桁数
int digitsum(int n){int ret=0; while(n>0){ret+=n%10;n/=10;}return ret;} //桁和
int lesscount(int x,Vi &a){return lower_bound(a.begin(),a.end(),x)-a.begin();} //vector aにおけるx未満の数の個数
int orlesscount(int x,Vi &a){return upper_bound(a.begin(),a.end(),x)-a.begin();} //vector aにおけるx以下の数の個数
int morecount(int x,Vi &a){return a.size()-orlesscount(x,a);} //vector aにおけるxより大きい数の個数
int ormorecount(int x,Vi &a){return a.size()-lesscount(x,a);} //vector aにおけるx以上の数の個数
int count(int x,Vi &a) {return upper_bound(ALL(a),x)-lower_bound(ALL(a),x);} //vector aにおけるxの個数
Vi accum(Vi &v){Vi ret((v).size()+1);REP(i,0,(v).size()) ret[i+1]=ret[i]+v[i];return ret;}
bool comp(Pii a,Pii b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

signed main(){cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);
    int n;
    cin>>n;
    Vi a(n);
    REP(i,0,n) cin>>a[i];

    vector<VVi> dp(n+1,VVi(2,Vi(2,-INF)));
    dp[0][0][0]=0;
    REP(i,0,n){
        if(i%2==1 || i==0){
            chmax(dp[i+1][1][1],dp[i][0][0]+a[i]);
            chmax(dp[i+1][0][0],dp[i][0][0]);
            chmax(dp[i+1][0][0],dp[i][0][1]);
            chmax(dp[i+1][1][0],dp[i][1][0]);
            chmax(dp[i+1][1][0],dp[i][1][1]);
        }else{
            chmax(dp[i+1][1][1],dp[i][1][0]+a[i]);
            chmax(dp[i+1][0][1],dp[i][0][0]+a[i]);
            chmax(dp[i+1][0][0],dp[i][1][0]);
            chmax(dp[i+1][0][0],dp[i][1][1]);
        }
    }
    if(n%2==0) cout<<max(dp[n][1][0],dp[n][1][1])<<endl;
    else cout<<max(dp[n][0][0],dp[n][0][1])<<endl;
    // cout<<dp[n][n/2][0]<<endl;
    // cout<<dp[n][n/2][1]<<endl;

//    REP(i,0,n+1) vvout(dp[i]);
    return 0;
}
