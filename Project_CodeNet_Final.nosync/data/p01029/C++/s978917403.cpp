#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstring>
#include<sstream>
#include<complex>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < int(Y);++(X))
#define rrep(X,Y) for (int (X) = int(Y-1);(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int v,e;

int main(){
  int i,j,k;
  cin>>v>>e;
  vector<char> cs(v);
  vector<int> edges[v];
  rep(i,v)
    cin>>cs[i];
  int te,mp;
  rep(i,e){
    cin>>te>>mp;
    edges[te].pb(mp);
    edges[mp].pb(te);
  }
  rep(i,v){
    if(cs[i]!='?')continue;
    vector<int> memo(256,0);
    rep(j,edges[i].size())
      memo[cs[edges[i][j]]]=1;
    char cc;
    for(cc='a';cc<='z';cc++)
      if(!memo[cc])break;
    cs[i]=cc;
  }
  rep(i,v)
    cout<<cs[i];cout<<endl;
  return 0;
}
