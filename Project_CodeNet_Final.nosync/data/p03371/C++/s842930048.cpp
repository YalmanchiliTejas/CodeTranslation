#include<bits/stdc++.h>
using namespace std;

int main(){
  long long A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  long long sum, tmp;
  
  
  for(int i=0; i<max(X, Y)+1; i++){
 	tmp = i*C*2;
    if(X>i) tmp += (X-i)*A;
    if(Y>i) tmp += (Y-i)*B;
    
    sum = min(sum, tmp);
 
  }
  
  cout << sum << endl;
  return 0;
}