#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;cin>>N;
  vector<int> H(N);
  for(int i=0; i<N; i++)cin>>H[i];
  int m=0,c=0;
  for(int i=0; i<N; i++){
    if(m<=H[i]){
      c++;
      m=H[i];
    }
  }
  cout<<c<<endl;
}