#include<iostream>
#include<string>
#include<cstring>
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
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
#define PI 3.141592653589793

int main(){
  int N; cin >> N; ll a[N];
  rep(i, N){
    cin >> a[i];
  }
  sort(a, a+N); ll pm = 0, mp = 0;
  if(N%2){
    rep(i, N){
      if(i<N/2) pm-=(2*a[i]);
      else if(i==N/2 || i==(N+1)/2) pm+=a[i];
      else pm+=(2*a[i]);
    }
    rep(i, N){
      if(i<N/2 - 1) mp-=(2*a[i]);
      else if(i==N/2 - 1 || i==N/2) mp-=a[i];
      else mp+=(2*a[i]);
    }
    //cout << mp <<  " " << pm << endl;
    cout << max(pm, mp) << endl; return 0;
  }
  rep(i, N){
    if(i<N/2 - 1) mp-=(2*a[i]); 
    else if(i==N/2 - 1) mp-=a[i];
    else if(i==N/2) mp+=a[i];
    else mp+=(2*a[i]);
  }
  cout << mp << endl;
}