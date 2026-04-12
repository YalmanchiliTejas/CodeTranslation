#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<tuple>
#include<ctime>
#include<functional>
#include<cmath>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> p; 
#define rep(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("Yes")
#define p_no() p("No")
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))

int main(){
   ll N,a[200010];
   cin>>N;
   
   ll mod=1000000007;
   ll sum=0;
   for(int i=0;i<N;i++){
       cin>>a[i];
       sum+=a[i];
       sum%=mod;
   }
   ll ans=0;

   for(int i=0;i<N;i++)
   {
       sum-=a[i];
       if(sum<0) sum+=mod;

       ans+=a[i]*sum;
       ans%=mod;
   }
    cout<<ans<<endl;
   }