#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
//using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,x,m;
    cin>>n>>x>>m;
    ll ans=0,a=x,l,c,r;
    vec num(m,0);
    if(n<m+1){
        rep(i,n) ans+=a,a=a*a%m;
        cout<<ans;
        return 0;
    }
    rep(i,m+1){
        if(num[a]==0) num[a]++;
        else{
            r=i,c=a;
            break;
        }
        ans+=a,a=a*a%m;
    }
    ll sum=0;
    a=x;
    rep(i,m+1){
        if(a==c){
            l=i;
            break;
        }
        sum+=a,a=a*a%m;
    }
    ll s=r-l,p=ans-sum;
    ll nn=n-l;
    sum+=nn/s*p;
    nn%=s;
    a=c;
    rep(i,nn) sum+=a,a=a*a%m;
    cout<<sum;
}