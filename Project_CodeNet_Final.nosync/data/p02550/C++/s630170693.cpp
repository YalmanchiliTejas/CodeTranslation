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
#define mod 998244353
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

const int MAXN = 101010;
int n,x,m;
int a[MAXN],ss[MAXN];

signed main(){
IOS;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
  
  cin >> n >> x >> m;
  if(n==1){
    cout << x << endl;
    return 0;
  }
  a[1]=x;
  int sum = x;
  int ans = 0, p = 1, rem = 0;
  // set<int> s;
  map<int,int> s;
  s[x]=1;
  ss[1]=x;
  for(int i=2;;i++){
    a[i] = (a[i-1]*a[i-1])%m;
    sum+=a[i];
    ss[i]=sum;
    // cerr << sum << " " << a[i] << endl;
    if(a[i]==0 || i==n ){
      cout << sum << endl;
      return 0;
    }
    if(s.find(a[i])!=s.end()){
      sum-=a[i];
      p = i-s[a[i]];
      ans+=ss[s[a[i]]-1];
      sum-=ss[s[a[i]]-1];
      n-=(s[a[i]]-1);
      ans+=((sum)*(n/p));
      rem = (n%p);
      for(int j=s[a[i]];j<rem+s[a[i]];j++){
        ans+=a[j];
      }
      break;
    }
    s[a[i]]=i;
  }
  // cerr << p << endl;
  // for(int i=1;i<=rem;i++){
  //   ans+=a[i];
  // }
  cout << ans << endl;



return 0;
}
///....
