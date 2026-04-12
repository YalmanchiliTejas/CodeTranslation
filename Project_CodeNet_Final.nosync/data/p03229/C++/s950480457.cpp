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
/*
ソートして半分に割って
大きいほう小さいほうに分けて
交互に要素を並べればいい
この時大きいほうの最大値は内側に最小値は外側に
小さいほうの最小値は内側に最大値は外側に
 */
int n;
ll calc(ll *a){
    ll ret=0;
    for(int i=1;i<n;i++){
        ret+=abs(a[i]-a[i-1]);
    }
    return ret;
}
int main(){
    cin>>n;
    ll a[n];
    rep(i,n) cin>>a[i];
    sort(a,a+n);
    
    if(n%2==0){
        ll b[n/2],s[n/2];
        for(int i=0;i<n/2;i++){
            s[i]=a[i];
        }
        for(int i=n/2;i<n;i++){
            b[i-n/2]=a[i];
        }
        ll ans[n];
        //s[n-1]とb[0]を端
        ans[n-1]=s[n/2-1];ans[0]=b[0];
        rep(i,n){
            if(i==0||i==n-1) continue;
            if(i%2==0){
                ans[i]=b[i/2];
            }
            else{
                ans[i]=s[i/2];
            }
        }
        cout<<calc(ans)<<endl;
    }   
    else{
        //問題はこっちじゃんね
        //中央値は必ず端か
        //もう一方の端はsmallの最大値かbigの最小値
        ll s[n/2]={},b[n/2]={},mid;
        int index=0;
        for(;index<n/2;index++){
            s[index]=a[index];
        }
        mid=a[index];
        index++;
        for(;index<n;index++){
            b[index-n/2-1]=a[index];
        }
        ll ans1[n],ans2[n];
        ans1[n-1]=mid;ans2[n-1]=mid;
        //0,2,4,..をbigにするかsmallにするかで分ける。
        sort(s,s+n/2,greater<ll>());
        for(int i=0;i<n-1;i++){
            if(i%2==0){
                ans1[i]=s[i/2];
                ans2[i]=b[i/2];
            }
            else{
                ans1[i]=b[i/2];
                ans2[i]=s[i/2];
            }
        }
        cout<<max(calc(ans1),calc(ans2))<<endl;
    }
    return 0;
}