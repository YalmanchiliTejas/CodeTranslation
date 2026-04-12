#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <functional>
#include <utility>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#include <map>
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
typedef long long int ll;
const ll  MOD = 1000000007;
typedef pair<ll,ll> P;
const ll INF = 100100100100100100;

ll N;
ll a[200200];
int main(){
  cin >> N;
  rep(i,N){
    cin >> a[i];
  }
  for(int i=N-1;i>=0;i-=2){
    if(i == N-1) cout << a[i];
    else cout << " " <<  a[i];
  }
  if(N%2 == 0){
    for(int i=0;i<N;i+=2){
      cout << " " << a[i];
    }
  }
  else{
    for(int i=1;i<N;i+=2){
      cout << " " << a[i];
    }
  }
  cout << endl;
}
