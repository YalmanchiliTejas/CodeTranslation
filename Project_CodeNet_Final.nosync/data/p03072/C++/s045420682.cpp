#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int main(void){
  int n,h[25],ans=1;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  int hma=h[0];
  for(int i=1;i<n;i++){
    if(hma<=h[i]){
      hma=h[i];
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
