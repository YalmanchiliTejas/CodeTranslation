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
#include<numeric>
// #include <numeric>
using namespace std;



typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vint;
typedef vector<vector<ll>> vvint;
typedef vector<vector<vector<ll>>> vvvint;
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
#define LLONG_MAX 9223372036854775806
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

void comb(vector<vector <long long int> > &v){
  for(int i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(int k = 1;k <v.size();k++){
    for(int j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
}


struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> num;

    UnionFind(int N) : par(N), num(N) { //最初は全てが根であるとして初期化
      for(int i = 0; i < N; i++) par[i] = i;
      for(int i = 0; i < N; i++) num[i] = 1;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        num[ry] = num[rx] + num[ry];
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x){
      return num[root(x)];
    }


};

vint divisor(ll n){ // nの約数
  vint ret;
  for(ll i=1;i*i<=n;i++){
    if(n%i == 0){
      ret.pb(i);
      if(i*i!=n) ret.pb(n/i);
    }
  }
  vsort(ret);
  return ret;
}

ll my_pow(ll x,ll y){
  ll rtn=1;
  rep(i,y) rtn*=x;
  return rtn;
}

ll get_digit_in(ll n, ll i){ // i桁目の数字を得る。
  for(ll j=0;j<i-1;j++){
    n/=10;
  }
  return n%10;
}

ll get_digit(ll n){
  ll rtn=0;
  while(n>0){
    n/=10;
    rtn++;
  }
  return rtn;
}

ll solve(ll n, ll x, ll cnt){
  ll total = my_pow(2, n+2) - 3;
  if(n==0) return cnt+1;
  if(x==1) return cnt;
  if(x==total) return cnt + my_pow(2, n+1) - 1;
  if(x==(total/2+1)){
    return 1 + my_pow(2, n) - 1 + cnt;
  }

  if(x<(total/2+1)){
    return solve(n-1, x-1, cnt);
  }else{
    return solve(n-1, x-(total/2)-1, cnt+my_pow(2, n));
  }

}


int main() {
  cout<<fixed<<setprecision(10);

  ll n,x;cin>>n>>x;

  cout<<solve(n,x,0)<<endl;

}




//
