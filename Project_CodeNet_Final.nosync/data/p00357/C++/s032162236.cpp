#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,max1=0,max2=0;
  cin>>n;
  vector<int> d(n);
  for(int i=0;i<n;++i){
    cin>>d[i];
    d[i]/=10;
  }
  for(int i=0;i<n-1;++i){
    if(max1<i) break;
    max1=max(max1,i+d[i]);
  }
  for(int i=n-1;i>0;--i){
    if(max2<n-i-1) break;
    max2=max(max2,n-i-1+d[i]);
  }
  cout<<((max1>=n-1&&max2>=n-1)?"yes":"no")<<endl;
  return 0;
}

