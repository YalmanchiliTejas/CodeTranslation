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

int main()
{
  int N;
  cin >> N;

  if( N == 7 || N == 5 || N == 3 )
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}

