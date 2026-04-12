#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >>N;
  
  int ans;
  
  if(N<15) ans = 800*N;
  else ans = 800*N - 200*(N/15);
  
  cout <<ans<<endl;
}
