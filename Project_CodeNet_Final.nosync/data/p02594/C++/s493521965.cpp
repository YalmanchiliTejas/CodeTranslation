#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; i++)
#define RFOR(i, a, n) for (ll i = (ll)n - 1; i >= (ll)a; i--)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) RFOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define bra(first, second) '(' << first << ',' << second << ')'
constexpr ll MOD = 1000000007;
//constexpr ll MOD = 998244353;
ll INF = 1001001001001001001;
long double EPS = 1e-9;
long double PI = 3.141592653589793238;
template <typename T>
void remove(std::vector<T> &vector, unsigned int index)
{
   vector.erase(vector.begin() + index);
}

using Graph = vector<vector<tuple<ll, ll, ll>>>;

// MOD確認
 
int main(){
   ll X;
   cin >> X;
   if(X >= 30) cout << "Yes" << endl;
   else cout << "No" << endl;
}