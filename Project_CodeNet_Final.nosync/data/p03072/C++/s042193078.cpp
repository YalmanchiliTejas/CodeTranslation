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
using namespace std;



typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vint;
typedef vector<vector<ll>> vvint;
typedef pair<ll,ll> pint;
typedef vector<pint> vpint;

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
#define vmax(vec) *max_element(vec.begin(), vec.end())
#define vmin(vec) *min_element(vec.begin(), vec.end())
#define vsort(vec) sort(vec.begin(), vec.end())



int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0,};



// int binary_search(int key){
//  //isOKを満たす要素のうち最小のインデックスを返す。（要ソート）
//   int left = -1;
//   int right = N;
//
//   while(right - left > 1){
//     int mid = left + (right - left)/2;
//
//     if(isOK(mid, key)) right=mid;
//     else left=mid;
//   }
//
//   return right;
// }




int main() {


  ll N;
  cin >> N;
  vint H(N);
  ll ans=0;
  ll tmp=0;
  rep(i,N){
    cin >> H[i];
    if(tmp<=H[i]){
      ans++;
      tmp=max(tmp,H[i]);
    }
  }

  cout << ans << endl;



}

















//
