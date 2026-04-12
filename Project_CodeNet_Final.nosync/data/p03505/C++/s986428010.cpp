#include<bits/stdc++.h>
using namespace std;

int main(){
  long long K,A,B;
  cin >> K >> A >> B;
  if(K>A && A<=B){cout << -1 << endl; return 0;}
  else if(A<=B){cout << 1 << endl; return 0;}
  long long q=(K-B+A-B-1)/(A-B);
  cout << q*2-1 << endl;
}