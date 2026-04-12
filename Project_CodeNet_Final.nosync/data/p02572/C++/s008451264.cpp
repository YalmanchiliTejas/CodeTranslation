#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> lP;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int main(){
    int n;
    cin>>n;
    vector<ll> a;
    rep(i,n){
        int b;
        cin>>b;
        a.push_back(b);
    }

    vector<ll> s(n+1);
    s[0]=0;
    rep1(i,n){
        s[i]=s[i-1]+a[i-1];
        s[i]%=mod;
    }

    ll ans=0;
    rep(i,n-1){
        int v=s[n]-s[i+1];
        if(s[n]-s[i+1]<0){
            v+=mod;
        }
        ans+=a[i]*v;
        ans%=mod;
    }

    cout<<ans<<endl;

}