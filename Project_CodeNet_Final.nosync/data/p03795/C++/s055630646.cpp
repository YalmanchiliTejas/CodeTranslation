#include <bits/stdc++.h>
#include <map> // pair
using namespace std;
int main(){
  int N;
  cin>>N;

  int ans = 800*N;
  if(N>14)ans-=200*(N/15);
  cout<<ans<<endl;
  }
