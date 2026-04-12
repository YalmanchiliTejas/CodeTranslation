#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4

int main(){
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  
  int bill = 0;
  if (A+B>2*C) {
    bill += 2*min(X,Y)*C;
    if (X>=Y) {
      bill += min((X-Y)*A, 2*(X-Y)*C);
    }
    else {
      bill += min((Y-X)*B, 2*(Y-X)*C);
    }
  }
  else {
    bill += A*X + B*Y;
  }

  cout << bill << endl;

  return 0;
}