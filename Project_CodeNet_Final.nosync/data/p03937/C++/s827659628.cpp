#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int poww[100];

int main(){
  int h,w;
  cin >> h >> w;
  char a[h][w];
  rep(i,h){
    rep(j,w)cin >> a[i][j];
  }
  poww[0]=1;
  rep(i,h)poww[i+1]=w*poww[i];
  vector<int> v;
  rep(i,poww[h]){
    v.clear();
    int temp=i;
    int sum=0;
    while(temp>0){
      sum+=temp%w;
      v.push_back(temp%w);
      temp/=w;
    }
    if(sum==w-1){
      bool ok=true;
      int tempw=0;
      int cnt=0;
      rep(j,h){
        for(int k=0;k<w;k++){
          if(a[j][k]=='#')cnt++;
          if(tempw<=k && k<=tempw+v[j] && a[j][k]=='.')ok=false;
        }
        tempw+=v[j];
      }
      if(ok && cnt==h+w-1){
        cout << "Possible" << endl;
        return 0;
      }
    }
  }
  cout << "Impossible" << endl;
return 0;}