#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_ll.hpp>
//typedef boost::multiprecision::cpp_ll ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define endl "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);



int main(){fastio
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    if(n%2==0){
        ll m=n/2;
        ll dp[m][2];
        rep(i,0,m-1)rep(j,0,1)dp[i][j]=-inf;
        dp[0][0]=a[0];
        dp[0][1]=a[1];
        rep(i,1,m-1){
            dp[i][0]=dp[i-1][0]+a[i*2];
            dp[i][1]=max(dp[i-1][0]+a[i*2+1],dp[i-1][1]+a[i*2+1]);
        }
        cout<<max(dp[m-1][0],dp[m-1][1])<<endl;
    }else{
        ll m=(n-1)/2;
        ll dp[m][2];
        rep(i,0,m-1)rep(j,0,1)dp[i][j]=-inf;
        dp[0][0]=a[0];
        dp[0][1]=a[1];
        rep(i,1,m-1){
            dp[i][0]=dp[i-1][0]+a[i*2];
            dp[i][1]=max(dp[i-1][0]+a[i*2+1],dp[i-1][1]+a[i*2+1]);
        }
        reverse(a,a+n);
        ll dp1[m][2];
        rep(i,0,m-1)rep(j,0,1)dp1[i][j]=-inf;
        dp1[0][0]=a[0];
        dp1[0][1]=a[1];
        rep(i,1,m-1){
            dp1[i][0]=dp1[i-1][0]+a[i*2];
            dp1[i][1]=max(dp1[i-1][0]+a[i*2+1],dp1[i-1][1]+a[i*2+1]);
        }
        reverse(a,a+n);
        ll maxi=-inf;
        rep(i,-1,m-1){
            if(i==-1){
                maxi=max(maxi,max(dp1[m-1][0],dp1[m-1][1]));
            }else if(i==m-1){
                maxi=max(maxi,max(dp[m-1][0],dp[m-1][1]));
            }else{
                maxi=max(maxi,max(dp[i][0],dp[i][1])+max(dp1[m-2-i][0],dp1[m-2-i][1]));
            }
        }
        cout<<maxi<<endl;
    }
    
    
    return 0;
}



