#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <complex>
#include <vector>
#include <limits>
#include <iomanip>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define debug(x) cout << #x << " = " << (x) << endl;
#define rep(i, n) for(int i = 0;i < n;i++)
#define repr(i, n) for(int i = n-1;i >= 0;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second

const long double pi = 3.141592653589793;
const int mod = 998244353;

ll N;
int vis[1<<20], X, M;
vector<ll> A;

int main() {

 // freopen("input.in","r",stdin);
 // freopen("output.out","w",stdout);

 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cin>>N>>X>>M;
 int j = 0;
 A.pb(X);
 vis[X]=1;
 j++;

 int aj = -1;
 while (1) {
   aj = (A[j-1]*A[j-1])%M;
   if(vis[aj]) {
     break;
   }
   A.pb(aj);
   j++;
   vis[aj]=1;
 }
 int i = 0;
 for(;i < j;i++) {
   if(A[i]==aj) break;
 }

 ll ans = 0;
 if(N <= i) {
   rep(k,N)ans+=A[k];
   cout<<ans;
   return 0;
 }

 rep(k,i)ans+=A[k];
 N -= i;
 ll tsum=0;
 for(int k = i;k<j;k++) tsum+=A[k];
 ans += (N/(j-i))*tsum;

 rep(k,N%(j-i)) ans+=A[i+k];
 cout<<ans;

 return 0;
}
