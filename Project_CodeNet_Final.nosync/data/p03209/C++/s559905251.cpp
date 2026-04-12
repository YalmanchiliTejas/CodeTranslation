#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef unsigned long ul;
typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<double> vd;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef pair<long,long> pll;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,n) for(int i=a;i<n;i++)
#define ALL(a) (a).begin(),(a).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))

#define pi 3.14159265358979
#define eps 1e-9
#define inf 1<<30
#define MOD 1000000007 // 1e9+7

vector<long long> nums(51);
vector<long long> pn(51);

ll calc(int n, ll x){
  if( n == 0 ){
    if( x == 0 ) return 0;
    else return 1;
  }
  if( x <= 1 ) return 0;
  if( x <  1 +   nums[n-1] ) return calc(n-1, x-1);
  if( x <= 1 +   nums[n-1] ) return pn[n-1];
  if( x <= 2 +   nums[n-1] ) return pn[n-1] + 1;
  if( x <  2 + 2*nums[n-1] ) return pn[n-1] + 1 + calc(n-1, x-nums[n-1]-2);
  return 2*pn[n-1] + 1;
}

int main()
{
  int N;
  cin >> N;
  ll X;
  cin >> X;

  nums[0] = 1;
  pn[0] = 1;
  for( int i=0; i<N; i++ ){
    nums[i+1] = 2*nums[i] + 3;
    pn[i+1] = 2*pn[i] + 1;
  }

  cout << calc(N, X) << endl;

  return 0;
}

