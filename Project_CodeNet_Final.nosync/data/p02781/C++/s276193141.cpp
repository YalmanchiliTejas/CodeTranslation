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
#define chmax(x,a) x=c_max(x,a)
#define chmin(x,a) x=c_min(x,a)
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
#define greater greater<int>()
inline ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
inline ll lcm(ll a,ll b){return a*b/GCD(a,b);}
using Edge=pair<int,ll>;
using Graph=vector<vector<bool> >;//ll or Edge
using Edge=pair<int,ll>;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
// g++ -o a a.cpp -Wall -lm -std=c++17
string n;
int K;
ll dp[110][2][4];
/*
dp[i][smaller][k]:=i桁目以降で0以外の数を使用できるのが残りk個である数の個数
i桁目までの部分について, smallerがtrueならnより小さく, falseならnと等しいとする.
*/

ll rec(int i=0,bool smaller=false,int k=K){
    if(k==0)return 1;
    if(i>=(ll)n.size())return 0;
    ll &ret=dp[i][(int)smaller][k];
    if(ret>0)return ret;
    ret=0;
    if(smaller){
        ret+=rec(i+1,true,k);
        ret+=rec(i+1,true,k-1)*9LL;
    }else {
        if(n[i]=='0')ret+=rec(i+1,false,k);
        else {
            ret+=rec(i+1,true,k);
            ret+=rec(i+1,true,k-1)*(n[i]-'1');
            ret+=rec(i+1,false,k-1);
        }
    }
    return ret;
}
int main(){
    cin>>n;cin>>K;
    cout<<rec()<<endl;
}