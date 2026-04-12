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

bool graph[8][8];

int main()
{
  int N, M;
  cin >> N >> M;
  rep(i,M){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    graph[a][b] = true;
    graph[b][a] = true;
  }

  int ret = 0;
  vi p(N);
  rep(i,N) p[i] = i;
  do{
    if( p[0] != 0 ) continue;
    bool flag = true;
    rep(i,N-1){
      if( !graph[p[i]][p[i+1]] ){
        flag = false;
      }
    }
    if( flag )
      ret++;
  } while(next_permutation(p.begin(), p.end()));

  cout << ret << endl;

	return 0;
}

