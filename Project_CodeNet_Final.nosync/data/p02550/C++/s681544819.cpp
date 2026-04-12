#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define fi first
#define se second
#define endl '\n'
#define int int64_t
#define double long double
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using reverse_queue = priority_queue<T, vector<T>, greater<T>>;
mt19937_64 rnd(time(0));
const int64_t FIXED_RANDOM = rnd();
template<typename T> struct custom_hash{T operator()(T x)const{return (T) x^FIXED_RANDOM;}}; // check hash in whether int64 or int32
template<typename T1, typename T2> using hash_map = gp_hash_table<T1, T2, custom_hash<T1>>;
// Tao luyện kỹ thuật trong 8 năm mày luyện kỹ thuật trong buồng tắm nam
const int MAXN = (int) 2e5 + 2;
const int INF = numeric_limits<int>::max() >> 1;
const int MOD = (int) 998244353;

signed main(){
  ios_base::sync_with_stdio(0); 
  cin.tie(0);
  // freopen("FDT.txt", "r", stdin);
  int n, x, m;
  cin >> n >> x >> m;
  vector<int> rm;
  rm.push_back(x);
  map<int, int> mp;
  mp[x] = 0;
  int leap, from;
  while(true){
    int pr = rm.back();
    pr *= pr;
    pr %= m;
    if(mp.count(pr)){
      from = mp[pr];
      leap = rm.size() - from;
      break;
    }
    mp[pr] = rm.size();
    rm.push_back(pr);
  }
  n --;
  if(n < from){
    int sum = 0;
    for(int i = 0; i <= n; i ++) sum += rm[i];
    cout << sum;
    return 0;
  }
  int sum = 0;
  for(int i = 0; i < from ; i ++) sum += rm[i];
  int jump = 0;
  for(int i = from; i < rm.size(); i ++) jump += rm[i];
  n -= from;
  n ++;
  int leap_req = n/leap;
  sum += leap_req*jump;
  n %= leap;
  for(int i = 0; i < n; i ++){
    sum += rm[i + from];
  }
  cout << sum;
}