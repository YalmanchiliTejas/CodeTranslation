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
int fact(int n){
  if(n == 1)return 1;
  return n * fact(n-1);
  }


int main(){
  int r, g, b;
  cin >> r >> g >> b;
  cout << (((10*g+b)%4 == 0)?"YES":"NO") << endl;
}
