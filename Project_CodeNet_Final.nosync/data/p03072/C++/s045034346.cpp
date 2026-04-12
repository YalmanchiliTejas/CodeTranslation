#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
int main(){
  int n; cin>>n;
  int h[101];
  int i,j,k;
  for(i=0;i<n;i++){
    cin>>h[i];
  }

  int ans=0;
  int tmp=0;

  for(i=0;i<n;i++){
    if(h[i]>=tmp) ans++;
    tmp=max(h[i],tmp);
  }

  cout << ans << endl;

}
