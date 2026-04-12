#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<tuple>
#include<stack>
#include<queue>
#include<deque>
#include<sstream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<bitset>
#include<time.h>
#include<cstdlib>
#include<cassert>
#define ll long long
#define fi first
#define se second
using namespace std;

int n,m;
bool a[9][9];
                   
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout<<fixed;
#ifdef LOCAL_DEFINE
    freopen("in", "r", stdin); 
    freopen("out","w",stdout);
#endif
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int to,from;
    cin>>to>>from;
    to--;from--;
    a[to][from]=1;
    a[from][to]=1;
  }
  vector<int> v;
  for(int i=0;i<n;i++){
    v.push_back(i);
  }
  ll ans=0;
  do{
    if(v[0]!=0)break;
    bool flag=1;
    for(int i=0;i<(int)v.size()-1;i++){
      if(!a[v[i]][v[i+1]])flag=0;
    }
    if(flag)ans++;
  }while(next_permutation(v.begin(),v.end()));
  cout<<ans<<"\n";
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}