#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

ll ans=0;
void eat(ll X, ll N){
  ll sum = pow(2,N+2)-3;
  if(X >= sum/2 + 1){
    ans += pow(2, N);
    X -= sum/2;
    //    cout << ans << endl;
  }
  X-=1;
  if(N!=0 && X!=0){
    N-=1;
    eat(X, N);
  }
}




int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, X;
  cin >> N >> X;
  eat(X,N);
  cout << ans << endl;
  
  return 0;
  

}
