#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define lb(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define ub(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
using Pair = pair<ll,pair<int,int>>;
#define pq priority_queue<Pair, vector<Pair>, greater<Pair>> 
const ll mod=1000000007;
//const ll mod=998244353;
const ld pi=acos(-1.0);
const ll INF = 1LL<<61;
template<class T>bool chmax(T &a, const T &b) { 
  if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) {
  if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる




int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;

  vector<ll>p(n);
  rep(i,n){
    cin>>p[i];
  }

  vector<ll> ans0(n,-INF);
  vector<ll> ans1(n,-INF);
  vector<ll> ans2(n,-INF);

  if(n%2==0){
    ans0[0]=p[0];
    ans1[1]=p[1];
    for(int i=2;i<n;i++){
      chmax(ans0[i],ans0[i-2]+p[i]);
      if(i>=3) chmax(ans1[i],ans0[i-3]+p[i]);
      chmax(ans1[i],ans1[i-2]+p[i]);
    }
    cout << max(ans0[n-2],ans1[n-1]) << endl;
  }

  if(n%2==1){
    ans0[0]=p[0];
    ans1[1]=p[1];
    ans2[2]=p[2];
    for(int i=2;i<n;i++){
      if(i!=n-1) chmax(ans0[i],ans0[i-2]+p[i]);
      if(i>=3) chmax(ans1[i],ans0[i-3]+p[i]);
      if(i>=4) chmax(ans2[i],ans0[i-4]+p[i]);
      chmax(ans1[i],ans1[i-2]+p[i]);
      if(i>=3) chmax(ans2[i],ans1[i-3]+p[i]);
      chmax(ans2[i],ans2[i-2]+p[i]);
    }
    cout << max({ans0[n-3],ans1[n-2],ans2[n-1]}) << endl;
  }

}
