#include <iostream>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
const int INF=1e9;

int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int ans=INF;
  rep(i,X+1){
    int sum=A*i;
    int N=(X-i)*2, res=Y-N/2;
    sum+=N*C;
    if(res>0) sum+=res*min(B,C*2);
    ans=min(ans,sum);
  }
  cout << ans << endl;

  return 0;
}
