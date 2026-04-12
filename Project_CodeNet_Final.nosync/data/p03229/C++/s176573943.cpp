#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vll vector<ll>
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll n;std::cin >> n;
  vll a(n), l, r; re(i, n) std::cin >> a[i];
  if(n==2){
    std::cout << abs(a[0] - a[1]) << '\n';
    return 0;
  }
  sort(a.begin(), a.end());
  for(int i=0;i<(n%2==0?n/2-1:n/2);i++) l.push_back(a[i]),r.push_back(a[n-1-i]);

  vll A{l[0], r[r.size()-1], 0}, B{r[0], l[l.size()-1], 0};
  ll tmp = 0;
  re(i, l.size()){
    if(i!=0) tmp += abs(l[i] - r[i-1]);
    tmp += abs(l[i]-r[i]);
  }
  A[2] = tmp;
  tmp = 0;
  re(i, l.size()){
    if(i!=0) tmp += abs(r[i] - l[i-1]);
    tmp += abs(r[i]-l[i]);
  }
  B[2] = tmp;
  //std::cout << A[0] << " " << A[1] << " " << A[2]  << '\n';
  //std::cout << B[0] << " " << B[1] << " " << B[2]  << '\n';

  if(n%2==1){
    ll x = a[n/2];
    ll ans = max({A[2]+abs(A[0]-x), A[2]+abs(A[1]-x), B[2]+abs(B[0]-x),B[2]+abs(B[1]-x)});
    std::cout << ans << '\n';
  }else{
    ll x = a[n/2-1], y = a[n/2];
    ll ans = max({A[2]+abs(A[0]-x)+abs(A[1]-y), A[2]+abs(A[1]-x)+abs(A[0]-y)});
    ans = max({ans, B[2]+abs(B[0]-x)+abs(B[1]-y), B[2]+abs(B[1]-x)+abs(B[0]-y)});
    std::cout << ans << '\n';
  }
  return 0;
}
