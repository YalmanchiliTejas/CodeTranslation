#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int INF = 1e9;
const long long LINF = 1e18;


int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = 0;
  map<int,int> T;
  T[X] = A;
  T[Y] = B;
  if(A+B <= 2*C) ans = A*X + B*Y;
  else{
    ans = min(min(X,Y)*C*2 + (max(X,Y) - min(X,Y))*T[max(X,Y)],max(X,Y)*C*2);
  }
  cout << ans << endl;
}

