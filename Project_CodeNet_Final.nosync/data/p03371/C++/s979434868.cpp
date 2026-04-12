#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<set>
using namespace std;

typedef long long ll;

int A,B,C,X,Y;

ll sum = 0;

void solve(int x) {
  while(1) {
    sum += x;
    X--;
    Y--;
    if ( X == 0 || Y == 0 ) return;
  }
}

void solve1() {
  while(1) {
    if( A >= C*2 ) {
      sum += C*2;
      X--;
      if( X == 0 ) return;
    } else {
      sum += A;
      X--;
      if( X == 0 ) return;
    }
  }
}

void solve2() {
  while(1) {
    if( B >= C*2 ) {
      sum += C*2;
      Y--;
      if( Y == 0 ) return;
    } else {
      sum += B;
      Y--;
      if ( Y == 0 ) return;
    }
  }
}

int main() {
  cin >> A >> B >> C >> X >> Y;
  if ( A+B > C*2 ) solve(C*2);
  else if ( A+B < C*2 ) solve(A+B);
  else if ( A+B == C*2 ) solve(A+B);

  if ( X > Y ) solve1();
  else if ( X < Y ) solve2();
  
  cout << sum << endl;
  return 0;
}
