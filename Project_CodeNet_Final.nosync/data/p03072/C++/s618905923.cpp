#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >>N;
  int H[N];
  for(int i=0;i<N;i++){
    cin >>H[i];
  }
  int max=0;
  int ans=0;
  for(int i=0;i<N;i++){
    if(H[i]>=max){
      ans++;
      max=H[i];
    }
  }
  cout <<ans<<endl;
}