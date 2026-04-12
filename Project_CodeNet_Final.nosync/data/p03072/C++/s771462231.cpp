#include<bits/stdc++.h>
#define repeat(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int N; 
  cin >>N;
  
  vector<int> H(N);
  int ans=0;
  int max=0;
  repeat(i,N) {
    cin >>H[i];
    if(H[i]>=max){
      max=H[i]; 
      ans++;
    }
  }
  cout << ans << endl;
}