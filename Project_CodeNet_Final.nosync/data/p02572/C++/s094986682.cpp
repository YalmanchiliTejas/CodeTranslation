#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,c=0,d=0,b;
  b = 1000000007;
  cin >> n;
  vector<long long> a(n);
  for(int i=0; i < n ; i++) {
    cin >> a.at(i);
    if(a.at(i) >= b) a.at(i) -= b;
    if(i>0){
      c += a.at(i);
      if(c >= b) c -= b; 
    }
  }
  for(int i=0; i < n-1; i++){
    d += a.at(i) * c ;
    d = d % b;
    c -= a.at(i+1);
    if(c < 0) c += b;
    
  }
  cout << d;
}
