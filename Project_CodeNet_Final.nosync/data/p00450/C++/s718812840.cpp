#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
#include <cassert>
using namespace std;
static const double EPS = 1e-10;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PI;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define F first
#define S second
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

main(){
  int n;
  while(cin>>n,n){
    stack<PI> go;
    rep(i,n){
      int st;
      cin>>st;
      if(i%2){
	PI tp=go.top();go.pop();
	if(tp.F!=st){
	  tp.S++;
	  go.push(tp);
	}else{
	  if(!go.empty()){
	    PI tp2=go.top();go.pop();
	    tp2.S+=tp.S+1;
	    go.push(tp2);
	  }else{
	    tp.S++;
	    tp.F=!tp.F;
	    go.push(tp);
	  }
	}
      }else{
	if(!go.empty()){
	  PI tp=go.top();go.pop();
	  if(tp.F==!st){
	    tp.S++;
	    go.push(tp);
	  }else{
	    go.push(tp);
	    go.push(mp(!st,1));
	  }
	}else go.push(mp(!st,1));
      }
    }
    int ans=0;
    while(!go.empty()){
      int col=go.top().F,num=go.top().S;
      go.pop();
      if(col)ans+=num;
    }
    cout<<ans<<endl;
  }
}