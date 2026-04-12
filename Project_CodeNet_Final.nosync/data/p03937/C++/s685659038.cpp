#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
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

int main() {
  int H, W;
  cin>>H>>W;
  vector<string> A(H);
  for(int i=0;i<H;++i){
    cin>>A[i];
  }
  map<int, int> amap;
  for(int i=0;i<H;++i){
    for(int j=0;j<W;++j){
      if(A[i][j]=='#') amap[i+j]++;
    }
  }
  bool ans = true;
  for(int i=0;i<H+W-1;++i){
    if(amap[i]>1) ans = false;
  }
  if(ans) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}
