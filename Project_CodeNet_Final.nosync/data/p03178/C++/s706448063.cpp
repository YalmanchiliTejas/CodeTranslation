#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<int,int>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll dp[100005][2][102];//j 0超えてない 1超えている
int main(){
    string s;
    cin>>s;
    int d;
    cin>>d;
    dp[0][0][0]=1;
    int n=s.size();
    for(int i=0;i<n;i++){
        int t=s[i]-'0';
        for(int j=0;j<2;j++){
            for(int k=0;k<(j?10:t+1);k++){
                for(int r=0;r<d;r++){
            (dp[i+1][j||(!j&&k!=t)][(k+r)%d]+=dp[i][j][r])%=mod;
                }
            }
        }
    }
    cout<<(dp[n][0][0]+dp[n][1][0]-1+mod)%mod<<endl;
}
