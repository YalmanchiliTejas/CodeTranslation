#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
int mod =1000000007;
const double PI = acos(-1);
int main(){
    ll a,b,c,n,m;cin>>a>>b>>c>>n>>m;
    ll ans =INFL;
    rep(i,max(n,m)+2){
        ll sum =2*i*c;
        sum+=max(0LL,n-i)*a;
        sum+=max(0LL,m-i)*b;
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
}