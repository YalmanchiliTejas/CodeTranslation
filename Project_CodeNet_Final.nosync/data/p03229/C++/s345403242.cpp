#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main() {
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    sort(all(a));
    ll ans=0;
    vector<ll> s,b;
    if(n%2==0){
        rep(i,n/2) s.push_back(a[i]);
        rep(i,s.size()){
            if(i<s.size()-1) ans-=s[i]*2;
            else ans-=s[i];
        }
        rep(i,n/2) b.push_back(a[n-1-i]);
        rep(i,b.size()){
            if(i<b.size()-1) ans+=b[i]*2;
            else ans+=b[i];
        }
    }
    else{
        ll res1=0;
        rep(i,n/2) s.push_back(a[i]);
        rep(i,s.size()){
            res1-=s[i]*2;
        }
        rep(i,n/2+1) b.push_back(a[n-1-i]);
        rep(i,b.size()){
            if(i<b.size()-2) res1+=b[i]*2;
            else res1+=b[i];
        }
        s.clear();
        b.clear();
        ll res2=0;
        rep(i,n/2+1) s.push_back(a[i]);
        rep(i,s.size()){
            if(i<s.size()-2) res2-=s[i]*2;
            else res2-=s[i];
        }
        rep(i,n/2) b.push_back(a[n-1-i]);
        rep(i,b.size()){
            res2+=b[i]*2;
        }
        ans=max(res1,res2);
    }

    cout<<ans<<endl;
}

