#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
#define pb push_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define chmin(x,y) if(x>y)x=y
#define chmax(x,y) if(x<y)x=y
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,vector<ll>,greater<ll>> SPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
using vc=vector<char>;
using vvc=vector<vector<char>>;
const ll inf=100100100100;
const int Inf=1001001001;
const int mod=1000000007;
const double pi=3.141592653589793;

int main(){
    int n;cin>>n;
    vi v(n),x(n);
    ll ans=0;
    rep(i,n)cin>>x[i];
    rep(i,n)v[i]=x[i]+x[n-i-1];
    REP(i,1,n/2){
        ll sum=0;
      vector<bool> b(n,false);
      if(n%2==1)b[n/2]=true;
        for(int j=i;j<n;j+=i){
          if(b[j]||b[n-j-1])break;
          if(n-j-1<i)break;
            sum+=v[j];
            if(ans<sum){
              ans=sum;
            }
          b[j]=true;
        }
    }
    cout<<ans<<endl;
}
