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
  int N; cin >> N; ll ans = 0; ll S[N];
  rep(i, N){
    cin >> S[i];
  }
  N--;
  rep(i, N){
    int m = i+1; ll ato = 0, mae = 0;
    ll bai = N/m;
    if(N%m){
      rep(j, bai){
        ato+=S[N-m*j];
        mae+=S[m*j];
        ans = max(ans, mae+ato);
      }
    }
    else{
      rep(j, (bai+1)/2){
        ato+=S[N-m*j];
        mae+=S[m*j];
        ans = max(ans, mae+ato);
      }
    }
  }
  cout << ans << endl;  
}
