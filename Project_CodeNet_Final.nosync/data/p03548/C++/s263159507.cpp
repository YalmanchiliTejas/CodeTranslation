#include <bits/stdc++.h>
#define REP(i, n) for (int (i) = 0; (i) < (int)(n); i++) 
#define FOR(i, a, b) for(int (i) = a; (i) < (int)b; i++)
#define RREP(i, n) for(int (i)=((int)(n)-1); (i)>=0; i--)
#define RFOR(i, a, b) for(int (i) =((int)(b)-1); (i)>=(int)a; i--)
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define FT first
#define SC second

using namespace std ;
typedef long long ll;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef pair<int, int> pint;
const int INF = 1e9;
const double EPS = 1e-9;



int main()
{
  int x, y, z ;
  cin >> x >> y >> z ;
  int ans = 0 ;
  
  int n = 0 ;
  while(ans<=x){
    n++ ;
    ans = y*n+z*(n+1) ;
  }
  
  cout << n-1 <<endl ;

  return 0 ;
}


