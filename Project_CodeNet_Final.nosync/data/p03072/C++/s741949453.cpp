#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  int N;
  cin>>N;
  int H[N];
  rep(i,N){
      cin>>H[i];
  }
  int MAX=0;
  int cnt=0;
  
  rep(i,N){
      MAX=max(MAX,H[i]);
      if(H[i]==MAX){
          cnt++;
      }
  }
 
  cout<<cnt<<endl;
  
}