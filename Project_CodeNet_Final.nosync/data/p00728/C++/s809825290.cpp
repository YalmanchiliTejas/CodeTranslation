#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int i,n,sum = 0;
  int pt[1000];
  while(cin>>n,n){
    sum = 0;
    for(i = 0;i<n;i++) cin>>pt[i];
    sort(pt,pt + n);
    for(i = 1;i<n-1;i++){
      //cout<<pt[i]<<endl;
      sum += pt[i];
    }
    int tmp = sum/(n-2);
    cout<<sum/(n-2)<<endl;
  }
  return 0;
}