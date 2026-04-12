#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<algorithm> // sort
#include<map> // pair
#include<cmath>
#include<cstring>
#include<set>
using namespace std;
using ll = long long;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
const ll mod = 1e9+7;
const int INF = 1e9;
const ll INFLONG = 1e18;
vector<ll> vec;
ll lower(ll first,ll last,ll a){
  ll mid;
  while(first < last){
    mid = (first+last)/2;
    if(vec[mid] < a){
      first = mid + 1;
    }else{
      last = mid;
    }
  }
  if(vec[first] < a){
    return first;
  }else{
    return first-1;
  }
}
int main(){
  ll n;
  cin >> n;
  ll a[n];
  ll size=0;
  ll first,last;
  rep(i,n){
    cin >> a[i];
  }
  rep(i,n){
    if(i == 0 || a[i] <= vec[0]){
      vec.insert(vec.begin(),a[i]);
      size++;
    }else{
      first=0;
      last=size-1;
      first = lower(first,last,a[i]);
      //MSG(first);
      vec[first] = a[i];
    }

    rep(j,size){
      //cout << vec[j] << " ";
    }
    //cout << endl;
  }
  cout << size;
}
