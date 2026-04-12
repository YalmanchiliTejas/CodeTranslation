#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* na, Arg1&& arg1, Args&&... args) {
  const char* c = strchr(na + 1, ',');
  cerr.write(na, c - na) << " : " << arg1 << " , ";
  __f(c + 1, args...);
}
#define endl "\n"
typedef long long LL;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 2e5 + 5;

string s;
int k;

vector <int> V;
int len;
LL dp[1005][2][5];

LL go( int idx , int smaller , int cnt ) {
        if (cnt > k) return 0;
        if( idx >= len ) return cnt == k;
        if( dp[idx][smaller][cnt] != -1 ) return dp[idx][smaller][cnt];
        LL ret = 0;
        if( smaller ) {
                for( int i = 0; i <= 9; i++ ) {
                        ret += go( idx + 1 , 1 , cnt + (i != 0) );
                }
        }
        else {
                for( int i = 0; i < V[idx]; i++ ) {
                        ret += go( idx + 1 , 1 , cnt + (i != 0) );
                }
                ret += go( idx + 1 , 0 , cnt + (V[idx] != 0) );
        }
        return dp[idx][smaller][cnt]= ret;
}
LL solve( ) {
        V.clear();
        for (int i = 0; i < len; i++) V.push_back(s[i] - '0');
        memset( dp , -1 , sizeof( dp ) );
        return go( 0 , 0 , 0 );
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    //freopen("input.txt", "r", stdin);
  #endif // LOCAL
  cin >> s >> k;
  len = s.size();
  cout << solve() << endl;
  return 0;
}

