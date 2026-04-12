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
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, M;
  cin>>N>>M;
  vector<vector<int> > edge(N);
  int a, b;
  for(int i=0;i<M;++i) {
    cin>>a>>b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  vector<int> arr(N);
  for(int i=0;i<N;++i) arr[i] = i;
  bool can;
  bool tmpcan;
  int ans = 0;
  do {
    if(arr[0]!=0) continue;
    can = true;
    for(int i=0;i<N-1;++i) {
      tmpcan = false;
      for(int j=0;j<edge[arr[i]].size();++j) {
        if(edge[arr[i]][j]==arr[i+1]) tmpcan = true;
      }
      if(!tmpcan) can = false;
    }
    if(can) {
      ans++;
    }
  }while(next_permutation(arr.begin(), arr.end()));
  cout<<ans<<endl;
}

