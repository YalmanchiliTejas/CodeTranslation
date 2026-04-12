#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

vector<vector<int> > edge(10);

int main() {
  int N, M;
  cin>>N>>M;
  int a, b;
  for(int i=0;i<M;++i) {
    cin>>a>>b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  vector<int> node;
  for(int i=0;i<N;++i) node.push_back(i);
  int ans = 0;
  bool can, tmp;
  do {
    if(node[0]!=0) can = false;
    else can = true;
    for(int i=0;i<N-1;++i) {
      tmp = false;
      for(int j=0;j<edge[node[i]].size();++j) {
        if(edge[node[i]][j]==node[i+1]) tmp = true;
      }
      can = min(can, tmp);
    }
    if(can) {
      ans++;
    }
  }while(next_permutation(node.begin(), node.end()));
  cout<<ans<<endl;
}

