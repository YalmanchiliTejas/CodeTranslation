/*input
4 5
##...
.##..
..##.
...##
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define double long double

typedef pair<int,int> pi;

typedef vector<int> vi;
typedef vector<pi> vpi;

#define f first
#define s second
#define mp make_pair
#define pb push_back

#define gcd __gcd

const int INF = 1e18+1;
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;

int fast_ex(int a,int n,int m){
  if(n == 0)return 1;
  if(n == 1)return a;
  int x = 1;
    x *= fast_ex(a,n/2,m);
    x %= m;
    x *= x;
    x %= m;
    if(n%2)x*= a;
    x %= m;
    return x;
}

int i,j;

signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int ans = 0;
  int n,m;
  cin >> n >> m;
  for(i = 0;i < n;i++){
  	for(j = 0;j < m;j++){
  		char o;cin >> o;
  		if(o == '#')ans++;
  	}
  }
  if(ans == n+m-1)cout << "Possible";
  else cout << "Impossible";
  return 0;
}