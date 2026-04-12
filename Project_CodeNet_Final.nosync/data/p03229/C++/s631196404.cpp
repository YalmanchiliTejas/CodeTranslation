#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, a, n) for(int i=a; i<n; i++)
#define ll long long
#define all(x) begin(x), end(x)
#define toInt(x) (x - '0')
#define pll pair<ll, ll>
#define pli pair<ll, int>

const long long INF = 1LL<<60;
const int inf = 1 << 30;
const int mod = 1e9+7;


template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main(){
  int n;
  cin >> n;
  vector<long long> v(n);
  rep(i, 0, n){
    cin >> v[i];
  }
  sort(all(v));

  deque<long long> d;
  d.push_front(v[0]);

  int r = n-1;
  int l = 1;
  while(r >= l){
    d.push_front(v[r]);
    r--;
    if(r < l) break;
    d.push_back(v[r]);
    r--;
    if(r < l) break;
    d.push_front(v[l]);
    l++;
    if(r < l) break;
    d.push_back(v[l]);
    l++;
  }
  // for (auto it: d){
  //   cout << it << " ";
  // }
  // cout << endl;
  long long ans = 0;
  for (int i=0; i<n-1; i++){
    ans += abs(d[i] - d[i+1]);
  }

  d.erase(all(d));
  // for (auto it: d){
  //   cout << it << endl;
  // }
  d.push_front(v[n-1]);

  r = n-2;
  l = 0;
  while(r >= l){
    d.push_front(v[l]);
    l++;
    if(r < l) break;
    d.push_back(v[l]);
    l++;
    if(r <l) break;
    d.push_front(v[r]);
    r--;
    if(r < l) break;
    d.push_back(v[r]);
    r--;
  }
  // for (auto it: d){
  //   cout << it << " ";
  // }
  // cout << endl;
  long long ans2 = 0;
  for (int i=0; i<n-1; i++){
    ans2 += abs(d[i] - d[i+1]);
  }
  cout << max(ans, ans2) << endl;
}
