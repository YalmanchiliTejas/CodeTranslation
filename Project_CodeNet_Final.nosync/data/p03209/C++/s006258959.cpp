#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll L[51],P[51];
ll n,x;

ll layer(ll x){
    return ((ll)pow(2,x+2)-3ll);
}
ll patty(ll x){
    return ((ll)pow(2,x+1)-1ll);
}
ll solve(ll n,ll x){
    if(x<=n-1||x==0) return 0;
    else if(n==0) return 1;
    else if(x==L[n-1]+1) return P[n-1];
    else if(x==L[n-1]+2) return P[n-1]+1;
    else if(x<L[n-1]+1) return solve(n-1,x-1);
    else return solve(n-1,x-2-L[n-1])+P[n-1]+1;
}
int main(){
    for(ll i=0;i<51;i++){
        L[i]=layer(i);P[i]=patty(i);
    }
    cin>>n>>x;

    /*
    レベルKバーガー
    Layer(k)=2*Layer(k-1)+3
      Layer(k)=2^(k+2)-3
      →Layer(50)=4*10^15とか
    Patty(k)=2*patty(k-1)+1
      
    Ban(k)=2*Ban(k-1)+2
    Layer(k)=lのときlは奇数
    下からl/2と上からl/2は対象、一番真ん中はパティ
     */

    cout<<solve(n,x)<<endl;
    return 0;
}