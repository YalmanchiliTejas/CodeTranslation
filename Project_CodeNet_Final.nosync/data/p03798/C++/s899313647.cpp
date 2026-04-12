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
ll inf=(ll)1E18;
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
    string s;cin>>s;
    rep(i,0,3){
        ll ans[n];
        ans[0]=i%2;
        ans[1]=i/2;
        rep(i,2,n-1){
            ll sum=0;
            sum+=ans[i-2];
            sum+=ans[i-1];
            if(s[i-1]=='o'){
                sum++;
            }
            if(sum%2==0){
                ans[i]=0;
            }else{
                ans[i]=1;
            }
        }
        ll sum=0;
        sum+=ans[n-2];
        sum+=ans[n-1];
        sum+=ans[0];
        if(s[n-1]=='o'){
            sum++;
        }
        if(sum%2==1){
            continue;
        }
        sum=0;
        sum+=ans[n-1];
        sum+=ans[0];
        sum+=ans[1];
        if(s[0]=='o'){
            sum++;
        }
        if(sum%2==1){
            continue;
        }
        rep(i,0,n-1){
            if(ans[i]==1){
                cout<<"S";
            }else{
                cout<<"W";
            }
        }
        cout<<endl;
        return 0;
    }
    cout<<-1<<endl;
    
    return 0;
}



