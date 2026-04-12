#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <tuple>
#include <stack>
#include <bitset>
#include <utility>
#include<iomanip>
// #include <numeric>
using namespace std;



typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vint;
typedef vector<vector<ll>> vvint;
typedef vector<string> vstring;
typedef vector<vector<string>> vvstring;
typedef vector<char> vchar;
typedef vector<vector<char>> vvchar;
typedef vector<long double> vdouble;
typedef vector<vector<long double>> vvdouble;
typedef vector<vector<vector<long double>>> vvvdouble;
typedef pair<ll,ll> pint;
typedef vector<pint> vpint;
typedef vector<bool> vbool;

#define rep(i,n) for(ll i=0;i<n;i++)
#define repf(i,f,n) for(ll i=f;i<n;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define INT_MAX 2147483647
#define LLONG_MAX 9223372036854775807
#define vmax(vec) *max_element(vec.begin(), vec.end())
#define vmin(vec) *min_element(vec.begin(), vec.end())
#define vsort(vec) sort(vec.begin(), vec.end())
#define vsortgr(vec) sort(vec.begin(), vec.end(), greater<ll>())
#define DIVIDER 1000000007


//
// struct Node{
//   vint children;
//   ll index;
//   ll prop;
// };
// struct edge{ll to; ll cost;};



int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0,};

// ll X,Y,Z,K;
// ll pmax = 30000000000;
// vint A,B,C;




// struct UnionFind {
//     vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
//
//     UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
//         for(int i = 0; i < N; i++) par[i] = i;
//     }
//
//     int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
//         if (par[x] == x) return x;
//         return par[x] = root(par[x]);
//     }
//
//     void unite(int x, int y) { // xとyの木を併合
//         int rx = root(x); //xの根をrx
//         int ry = root(y); //yの根をry
//         if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
//         par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
//     }
//
//     bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
//         int rx = root(x);
//         int ry = root(y);
//         return rx == ry;
//     }
// };
//
// vint divisor(ll n){ // nの約数
//   vint ret;
//   for(ll i=1;i*i<=n;i++){
//     if(n%i == 0){
//       ret.pb(i);
//       if(i*i!=n) ret.pb(n/i);
//     }
//   }
//   vsort(ret);
//   return ret;
// }
//
// ll get_digits_num(ll n){
//   ll ret=0;
//   while(n){
//     n/=10;
//     ret++;
//   }
//   return ret;
// }



int main() {
  cout<<fixed<<setprecision(10);

  ll N;
  cin>>N;
  // cout<<N;
  vint A(N);
  rep(i,N)cin >> A[i];


  vsort(A);
  // rep(i,N)cout << A[i];
  ll ans =0;

  if(N==0){
    ll left, right;
    left = A[0];
    right = A[0];
    ll i = 1;
    ll l,r;
    l = 1;
    r = N-1;
    while(i<N-1){
      if(i%4==1){
        ans += abs(left-A[r]);
        left = A[r];
        r--;
      }else if(i%4==2){
        ans += abs(right-A[r]);
        right = A[r];
        r--;
      }else if(i%4==3){
        ans += abs(left-A[l]);
        left = A[l];
        l++;
      }else{
        ans += abs(right-A[l]);
        right = A[l];
        l++;
      }
      i++;
    }
    ans += max(abs(right-A[N/2]), abs(left-A[N/2]));
  }else{
    ll left, right;
    left = A[0];
    right = A[0];
    ll i = 1;
    ll l,r;
    l = 1;
    r = N-1;
    while(i<N){
      if(i%4==1){
        ans += abs(left-A[r]);
        left = A[r];
        r--;
      }else if(i%4==2){
        ans += abs(right-A[r]);
        right = A[r];
        r--;
      }else if(i%4==3){
        ans += abs(left-A[l]);
        left = A[l];
        l++;
      }else{
        ans += abs(right-A[l]);
        right = A[l];
        l++;
      }
      i++;
    }
  }
  ll anstmp = ans;

  vsortgr(A);
  ans =0;

  if(N==0){
    ll left, right;
    left = A[0];
    right = A[0];
    ll i = 1;
    ll l,r;
    l = 1;
    r = N-1;
    while(i<N-1){
      if(i%4==1){
        ans += abs(left-A[r]);
        left = A[r];
        r--;
      }else if(i%4==2){
        ans += abs(right-A[r]);
        right = A[r];
        r--;
      }else if(i%4==3){
        ans += abs(left-A[l]);
        left = A[l];
        l++;
      }else{
        ans += abs(right-A[l]);
        right = A[l];
        l++;
      }
      i++;
    }
    ans += max(abs(right-A[N/2]), abs(left-A[N/2]));
  }else{
    ll left, right;
    left = A[0];
    right = A[0];
    ll i = 1;
    ll l,r;
    l = 1;
    r = N-1;
    while(i<N){
      if(i%4==1){
        ans += abs(left-A[r]);
        left = A[r];
        r--;
      }else if(i%4==2){
        ans += abs(right-A[r]);
        right = A[r];
        r--;
      }else if(i%4==3){
        ans += abs(left-A[l]);
        left = A[l];
        l++;
      }else{
        ans += abs(right-A[l]);
        right = A[l];
        l++;
      }
      i++;
    }
  }


  ans = max(ans,anstmp);

  cout << ans << endl;


}

















//
