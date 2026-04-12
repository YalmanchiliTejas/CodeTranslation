#include<bits/stdc++.h>
using namespace std;

void solve(int n){
  bool ans = (n == 3) or (n == 5) or (n == 7);
  
  cout<<(ans ? "YES" : "NO")<<endl;
}

int main(){
  int n;
  
  cin>>n;

  solve(n);

  return 0;
}