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
static const double EPS = 1e-5;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> vi;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
#define f first
#define s second

const int B=10;

main(){
  int n;
  cin>>n;
  while(n--){
    vector< vector<int> > ans(B),tans,ban(B);
    rep(i,B){
      ans[i].resize(B);
      ban[i].resize(B);
    }
    rep(i,B)rep(j,B)cin>>ban[i][j];
    int mina=B*B;
    rep(k,1<<B){
      int tmin=0;
      rep(i,B){
        rep(j,B){
          if(!i)ans[i][j]=!!(1<<j&k);
          else{
            int t=ban[i-1][j]+ans[i-1][j];
            if(j)t+=ans[i-1][j-1];
            if(j+1<B)t+=ans[i-1][j+1];
            if(i>1)t+=ans[i-2][j];
            ans[i][j]=t%2;
          }
          tmin+=ans[i][j];
        }
      }
      rep(i,B){
        rep(j,B){
          int t=ans[i][j]+ban[i][j];
          if(j)t+=ans[i][j-1];
          if(i)t+=ans[i-1][j];
          if(j+1<B)t+=ans[i][j+1];
          if(i+1<B)t+=ans[i+1][j];
        }
      }

      int odd=0;
      rep(j,B){
        int t=ban[B-1][j]+ans[B-1][j]+ans[B-2][j];
        if(j)t+=ans[B-1][j-1];
        if(j+1<B)t+=ans[B-1][j+1];
        odd+=t%2;
      }
      if(!odd && tmin<mina){
        mina=tmin;
        tans=ans;
      }
    }
    rep(i,B){
      rep(j,B){
        if(j)cout<<" ";
        cout<<tans[i][j];
      }
      cout<<endl;
    }
  }
}