#include <iostream>
#include <string>

using namespace std;
typedef long long int ll;

#define MAX (int)2e5
#define MOD (((ll)1e9) + 7)

int main(void){
  int N;
  ll A[MAX];
  cin >> N;
  for(int i=0;i<N;i++){
    ll tmp;
    cin >> tmp;
    A[i] = tmp;
  }
  ll sum = A[0];
  ll ans = 0;
  for(int i=1;i<N;i++){
    ans = (ans + A[i]*sum)%MOD;
    sum = (sum + A[i])%MOD;
  }
  cout << ans << endl;
  return 0;
}