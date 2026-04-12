#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define inf 1e16
#define MOD 1e9+7
#define gcd __gcd //最大公約数,gcd(x,y)
int lcm(int a, int b){return a/gcd(a, b)*b;} //(int)最小公倍数,lcm(x,y)
ll llcm(ll a, ll b){return a/gcd(a, b)*b;}//(ll)最小公倍数,lcm(x,y)


int main(){
  int N,K,i;
  string S;
  char a;

  cin >> N >> S >> K;

  a = S[K-1];

  for(i=0 ; i<N ; i++){
    if(S[i] != a){
      S.replace(i,1,"*");
    }
  }
  cout << S << endl;
}
