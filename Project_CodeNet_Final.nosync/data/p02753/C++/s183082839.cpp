#include <bits/stdc++.h>
#define rep(i,n); for(int i = 0;i < (n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

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
int fact(int n){
  if(n == 1)return 1;
  return n * fact(n-1);
  }

int main(){
  string s;
  cin >> s;
  bool bus[2] = {false,false};
  string ans = "No";
  rep(i,3){
    if(s[i] == 'A' and bus[1] == false)bus[0] = true;
    else if(s[i] == 'A' and bus[1] == true)ans = "Yes";
    else if(s[i] == 'B' and bus[0] == false)bus[1] = true;
    else if(s[i] == 'B' and bus[0] == true)ans = "Yes";
  }
  cout << ans << endl;
}
