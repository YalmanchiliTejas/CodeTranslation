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

int N, M;
vvi path;
int cnt;

void loop(int id, int flag)
{
  if( flag & (1 << id) ) return;
  flag |= 1 << id;
  if( flag == (0b11111111 >> (8-N)) ){
    cnt++;
    return;
  }
  for( auto iter : path[id] )
    loop( iter, flag );
}

int main()
{
  int a, b;

  cin >> N >> M;
  path.resize(N);
  rep(i,M){
    cin >> a >> b;
    a--;
    b--;
    path[a].pb(b);
    path[b].pb(a);
  }

  cnt = 0;
  loop( 0, 0 );
  cout << cnt << endl;

	return 0;
}

