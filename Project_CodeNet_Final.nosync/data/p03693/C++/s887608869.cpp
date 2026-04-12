#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C; cin >> A >> B >> C;
  cout << ((100*A+10*B+C)%4==0?"YES":"NO") << endl;
}