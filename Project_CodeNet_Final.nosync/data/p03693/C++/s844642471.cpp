#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,ans;
  cin>>A>>B>>C;
  ans=A*100+B*10+C;
  if(ans%4==0) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;  
}
