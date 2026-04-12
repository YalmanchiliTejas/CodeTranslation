#include <bits/stdc++.h>
#define rep(i,n); for(int i = 0;i < (n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
long double pi = acos(-1);
const int INF = 1001001001;


// 最小公倍数を求める
int euqlid (int a, int b){
  int temp;
  temp = a % b;
  if(temp == 0)return b;
  return euqlid(b,temp);
}
ll conbination(ll a,ll b){
  ll u = 1;
  ll d = 1;
  while(b != 0){
    u *= a;
    d *= b;
    a--;
    b--;
  }
  return u / d;
}
int strtoint(char s){
  return (int(s-'0'));
}
char changeS(char alpha){
  if(0x41 <= alpha and alpha <= 0x5A)return (alpha + 0x20);
  else if(0x61 <= alpha and alpha <= 0x7A)return (alpha - 0x20);
  return alpha;
}
int fact(int n){
  if(n == 1)return 1;
  return n * fact(n-1);
  }



int main(){
  int n;
  cin >> n;
  cout << 800 * n - 200 * int(n/15) << endl;
}
