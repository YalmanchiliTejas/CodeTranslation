#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define A(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
void _read();
const int mod = 1e9+7;
template<typename T>
struct prefix_sum {
    vector<T> pref;
    int n;
    template<typename U>
    prefix_sum(vector<U> &vec) {

        n = vec.size();
        pref.resize(n);
        pref[0] = vec[0];
        for( int i = 1; i < n; i++) {
            pref[i] = pref[i-1] + vec[i];
            pref[i] %= mod;
        }
    }
    T sum ( int i ) {
        return pref[i];
    }
    T sum ( int i, int j ) {
        if ( i == 0 ) return pref[j];
        else return (pref[j] - pref[i-1] + mod) %mod;
    }
};
signed main () { _read(); 

      int n;
      cin >> n;
      vector<int> v(n);
      for( int &x : v ) cin >> x;
      prefix_sum<int> p(v);
      int sum = 0;
      for( int i = 0; i < n-1; i++ ) {
            (sum += (p.sum(i+1,n-1)*v[i])) %= mod;
      }
      cout << sum << '\n';
      return 0;
};

void _read() {
      ios_base :: sync_with_stdio(false);
      cin.tie(NULL);
      #ifdef LOCAL
      freopen("input.txt","r",stdin);
      #endif
}
