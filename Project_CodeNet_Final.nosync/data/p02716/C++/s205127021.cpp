/// kazuki08
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define ar array
//#define inf 1000000000
#define mod 1000000007
#define dmp(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl
#define fs first
#define sc second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
    return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
    o<<"{";
    for(const T& v:vc) o<<v<<",";
    o<<"}";
    return o;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
const int MAXN = 202000;
int a[MAXN],sumo[MAXN],sume[MAXN],sumr[MAXN];

signed main(){
IOS;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
  
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    sume[i] = sume[i-1];
    sumo[i] = sumo[i-1];
    if(i&1){
      sumo[i] += a[i];
    }
    else {
      sume[i] += a[i];
    }
  }

  if(n%2==0){
    int ans = max(sume[n],sumo[n]);
    for(int i=1;i<=n;i++){
      if(i&1){
        int cur = sumo[i]+sume[n]-sume[i+1];
        ans = max(ans,cur);
      }
    }
    cout << ans << endl;
  }
  else {
    int ans = sume[n];
    multiset<int> s;
    s.insert(sume[n]);
    int sum = 0;
    for(int i=n;i>=3;i--){
      if(i&1){
        sum+=a[i];
        int cur = sum + sume[i-2];
        s.insert(cur);
        ans = max(ans, sumo[i-3]+sum);
        sumr[i]=cur;
      }
    }
    ans = max(ans,sumo[n-1]);
    ans = max(ans,sumo[n]-a[1]);
    // cerr << ans << endl;
    for(int i=1;i<n-2;i++){
      if(i%2==0)continue;
      if(i+2<=n){
        // cerr << i << endl;
        s.erase(s.find(sumr[i+2]));
      }
      auto it = s.end();it--;
      ans = max(ans, sumo[i]+(*it)-sume[i+1] );
    }
    cout << ans << endl;
  }


return 0;
}
///....
