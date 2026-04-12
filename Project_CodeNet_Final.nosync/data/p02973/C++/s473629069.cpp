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
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,vector<ll>,greater<ll>> SPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
using vc=vector<char>;
using vvc=vector<vector<char>>;
const ll inf=100100100100;
const int Inf=1001001001;
const int mod=1000000007;
int main(){
    int n,ans=0;cin>>n;
    multiset<ll> s;
    vi v(n);
    rep(i,n)cin>>v[i];
    rep(i,n){
        auto it=s.lower_bound(v[i]);
        if(it==s.begin())ans++;
      else {
        it--;
        s.erase(it++);
      }
      s.insert(v[i]);
    }
    cout<<ans<<endl;
}
