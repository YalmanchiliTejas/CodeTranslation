#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define MOD (1000000007)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back

#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll keta(ll n){
  string s = to_string(n);
  ll num = s.size();
  return num;
}

const ll INF = 1LL << 60;

const int dh[4] = {1,0,-1,0};
const int dw[4] = {0,1,0,-1};

struct Edge{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w){}
};
using Graph = vector<vector<Edge>>;
using P = pair<ll, int>;


int main(){
  int n; cin >> n;
  vl a(n); rep(i,n) cin >> a[i];
  sort(all(a));
  deque<ll> b;
  b.push_back(a[0]);
  int j = n-1, k = 1;
  rep(i,n-1) {
    if(i%4 == 0){
      b.push_back(a[j]);
      j--;
    } 
    else if(i%4 == 1){
      b.push_front(a[j]);
      j--;
    }
    
    else if(i%4 == 2){
      b.push_back(a[k]);
      k++;
    }
    
    else if(i%4 == 3){
      b.push_front(a[k]);
      k++;
    }
  }
  ll sum1 = 0LL;
  //rep(i,n) cout << b[i] << " ";cout << endl;
  rep(i,n-1) sum1 += abs(b[i+1]-b[i]);

  reverse(all(a));
  b.resize(0);
  b.push_back(a[0]);
  j = n-1, k = 1;
  rep(i,n-1) {
    if(i%4 == 0){
      b.push_back(a[j]);
      j--;
    } 
    else if(i%4 == 1){
      b.push_front(a[j]);
      j--;
    }
    
    else if(i%4 == 2){
      b.push_back(a[k]);
      k++;
    }
    
    else if(i%4 == 3){
      b.push_front(a[k]);
      k++;
    }
  }
  ll sum2 = 0LL;
  //rep(i,n) cout << b[i] << " ";cout << endl;
  rep(i,n-1) sum2 += abs(b[i+1]-b[i]);

  ll ans = max(sum1,sum2);
  cout << ans << endl;
}
