#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,i,sum,max1;
  cin >> n;
  vector<int> h(n);
  for(i=0;i<n;++i){
    cin >> h[i];
  }
  sum=1;
  max1=h[0];
  for(i=1;i<n;i++){
    if(h[i]>=max1){
      sum=sum+1;
      max1=max(h[i],max1);
    }
  }
  cout << sum << endl;
  return 0;
}
