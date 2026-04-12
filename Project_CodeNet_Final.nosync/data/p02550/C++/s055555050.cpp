#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 998244353;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int main(){
    vector<ll> hai;
    ll n,x,m;
    cin>>n>>x>>m;
    bool judgeloop=false;
    bool judge1=false;
    bool judge0=false;
    ll markloop;
    rep(i,m){
        hai.push_back(x);
        if(i+1>=n) break;
        if(hai[i]==1) {
            judge1=true;
            break;
        }
        if(hai[i]==0){
            judge0=true;
            break;
        }
        x*=x;
        x%=m;
        ll elen=hai.size();
        rep(j,elen){
            if(hai[j]==x){
                judgeloop=true;
                markloop=j;
                break;
            }
        }
    }

    ll ans=0;
    ll len=hai.size();
    if(judge0){
        rep(i,len){
            ans+=hai[i];
        }
        //cout<<1<<endl;
    }
    else if(judge1){
        rep(i,len){
            ans+=hai[i];
        }
        ans+=(n-len);
        //cout<<2<<endl;
    }
    else if(judgeloop){
        ll imlen=len-markloop;
        ll loop=(n-markloop)/imlen;
        ll resi=(n-markloop)%imlen;
        ll sum=0;
        rep(i,markloop){
            ans+=hai[i];
        }
        rep(i,imlen){
            sum+=hai[markloop+i];
        }
        ans+=(sum*loop);
        rep(i,resi){
            ans+=hai[markloop+i];
        }
        //cout<<3<<endl;
    }
    else{
        rep(i,len){
            ans+=hai[i];
        }
        //cout<<4<<endl;
    }

    cout<<ans<<endl;
}