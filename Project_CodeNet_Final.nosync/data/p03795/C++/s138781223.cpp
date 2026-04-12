#include<iostream>
using namespace std;
int main(){
  int n,cnt=0;
  cin>>n;
  for(int i=1;i<n+1;i++){
    if(i%15==0)cnt++;
  }
  cout<<n*800-200*cnt<<endl;
}
