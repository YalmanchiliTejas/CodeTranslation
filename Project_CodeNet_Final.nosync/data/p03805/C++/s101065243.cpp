#include<bits/stdc++.h>
#define MAX 10
#define inf 1<<29
#define linf 1e16
#define eps (1e-8)
#define mod 1000000007
#define pi acos(-1)
#define phi (1.0+sqrt(5))/2.0
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define pd(a) printf("%.10f\n",(double)(a))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(a)-1;(b)<=i;i--)
#define equals(a,b) (fabs((a)-(b))<eps)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef vector<int> vi;
typedef vector<pii> vpi;
const int dx[8]={1,0,-1,0,1,1,-1,-1};
const int dy[8]={0,1,0,-1,1,-1,1,-1};

int n,m;
vector<int> g[MAX];
int ans=0;

void dfs(int v,int bits){
  if(bits==(1<<n)-1)ans++;
  else {
    FOR(i,0,g[v].size()){
      int next=g[v][i];
      if(bits&(1<<next))continue;
      dfs(next,bits|(1<<next));
    }
  }
}

int main()
{
  cin>>n>>m;
  FOR(i,0,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(0,1);
  cout<<ans<<endl;
  return 0;
}

