#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long LL;
typedef vector<ll>VI;
typedef vector<bool>VB;
typedef pair<ll,ll>P;
typedef pair<double,double>P_D;
#define VV(T) vector<vector<T>>
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define reprev(i, n) for (ll i = (ll)n - 1; i >= 0; i--)
#define bitrep(bit,A) for(int bit=A; ;bit=(bit-1)&A)
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) (ll)((a).size())
#define c_max(a, b) (((ll)a)>((ll)b)?(a):(b))
#define c_min(a,b) (((ll)a)<((ll)b)?(a):(b))
#define chmax(x,a) x=max(x,a)
#define chmin(x,a) x=min(x,a)
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define SORT(c) stable_sort(ALL(c))
#define $(x) {cout<<#x<<" = " <<(x)<<endl;}
#define fi first
#define se second
#define MAX 100100//5
#define MAX2 200100
#define MAX_6 1001001//6
#define MAX_7 10010010//7
#define SENTINEL 2000000000//9
#define NIL -1
const int MOD = 1000000007;
#define INF 1<<30
#define INFTY 1LL<<61
#define MAX_INT INT_MAX
#define Endl '\n'
inline ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
inline ll lcm(ll a,ll b){return a*b/GCD(a,b);}
using Edge=pair<int,ll>;
using Graph=vector<vector<bool> >;//ll or Edge
using Edge=pair<int,ll>;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
// sort_reverse...greater<ll>()
// g++ -o a a.cpp -Wall -lm -std=c++17

int main(){
    int n;cin>>n;
    VI a(n);rep(i,n)cin>>a[i];
    sort(ALL(a),greater<ll>());
    if(n%2==0){
        ll res=0;
        for(int i=0;i<n/2-1;i++)res+=a[i]*2;
        res+=a[n/2-1];
        res-=a[n/2];
        for(int i=n/2+1;i<n;i++)res-=a[i]*2;
        cout<<res<<endl;
    }
    else{
        ll res=0;
        for(int i=0;i<n/2-1;++i)res+=a[i]*2;
        res+=a[n/2-1]+a[n/2];
        for(int i=n/2+1;i<n;++i)res-=a[i]*2;
        ll res2=0;
        for(int i=0;i<n/2;i++)res2+=a[i]*2;
        res2-=a[n/2]+a[n/2+1];
        for(int i=n/2+2;i<n;i++)res2-=a[i]*2;
        cout<<max(res,res2)<<endl;
    }
    return 0;
}