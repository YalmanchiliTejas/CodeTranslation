#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin>>S;
  int a=0,b=0;
  rep(i,S.size()){
    if(S[i]=='A') a++;
    else b++;
  }
  if(a>0&&b>0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}
