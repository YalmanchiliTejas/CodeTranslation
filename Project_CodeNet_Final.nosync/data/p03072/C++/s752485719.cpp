#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >>N;
  int a[N];
  for(int i=0;i<N;i++){
    cin >>a[i];
  }
  int hi=a[0];
  int ans=1;
  for(int i=1;i<N;i++){
if(hi<=a[i]){
ans++;
  hi=a[i];
}
  }
  cout <<ans;
  }
    