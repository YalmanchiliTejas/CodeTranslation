#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)
#define ALL(x) (x).begin(),(x).end()
template<class T>bool umax(T &a, const T &b) {if(a<b){a=b;return 1;}return 0;}
template<class T>bool umin(T &a, const T &b) {if(b<a){a=b;return 1;}return 0;}

template<typename A,size_t N,typename T> void FILL(A (&array)[N],const T &val){fill((T*)array,(T*)(array+N),val);}
template<typename T> void FILL(vector<T> &v, const T &x) {fill(v.begin(), v.end(), x);}
template<typename T> void FILL(vector<vector<T>> &v, const T &x) {for(auto &i:v)fill(i.begin(), i.end(), x);}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
  ll n,x,m; cin >> n >> x >> m;

  vector<ll> index(m);
  vector<ll> sum(m);

  int a = x;
  set<int> s;
  for(ll i = 0; i < n; i++) {
    sum[i] += a;
    if(i!=0) sum[i] += sum[i-1];
    //printf("%5lld: %5d  %5lld\n",i, a, sum[i]);
    if(s.count(a)) {
      ll loop_start_index = index[a];
      ll loop_sum = sum[i] - sum[index[a]];
      ll loop_len = i - index[a];
      ll nokori = n - 1 - i;
      ll loop_nokori = nokori / loop_len;
      ll out_of_loop_nokori = nokori % loop_len;

      //cout << "loop detected at " << i << " (" << a << ")" << endl;
      //cout << "loop start at " << loop_start_index << endl;
      //cout << "loop sum    = " << loop_sum << endl;
      //cout << "loop length = " << loop_len << endl;
      //cout << "nokori      = " << nokori << endl;
      //cout << "nokori_loop = " << loop_nokori << endl;
      //cout << "nokori_out  = " << out_of_loop_nokori << endl;

      ll ans = sum[i - 1];
      ans += loop_nokori * loop_sum;
      if(loop_start_index > 0) ans += sum[loop_start_index+out_of_loop_nokori] - sum[loop_start_index-1];
      else                     ans += sum[loop_start_index+out_of_loop_nokori];
      cout << ans << endl;
      return 0;
    }
    index[a] = i;
    s.insert(a);
    a = modpow(a, 2, m);
  }
  cout << sum[n-1] << endl;
}
