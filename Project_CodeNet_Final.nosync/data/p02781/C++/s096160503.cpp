#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef  unsigned long long int ull;
typedef pair<ll,ll> P;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll dp[101][2][4];//何文字目までみたか,超えてないか,何桁か
int main(){
    string s;
    cin>>s;
    int n,d;
    cin>>d;
    n=s.size();
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        int tmp=s[i]-'0';
        for(int j=0;j<2;j++){
            for(int k=0;k<=(j?9:tmp);k++){
            for(int r=d-1;r>=0;r--){
                if(k==0)dp[i+1][j||(j!=1&&tmp!=k)][r]+=dp[i][j][r];
                else dp[i+1][j||(j!=1&&tmp!=k)][r+1]+=dp[i][j][r];
            }
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)for(int j=0;j<2;j++)ans+=dp[i][j][d];
    cout<<ans<<endl;
}