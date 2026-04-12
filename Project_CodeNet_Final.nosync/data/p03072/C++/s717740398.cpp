#include<iostream>
using namespace std;
int main()
{
  int N;
  cin>>N;
  int H[N];
  for(int i=0;i<N;i++){
    cin>>H[i];
  }
  int sum=0;
  bool flag=true;
  for(int i=0;i<N;i++){
    for(int j=0;j<i;j++){
      if(H[i]<H[j]){
        flag=false;
        break;
      }
    }
    if(flag){
      sum++;
    }
    else{
      flag=true;
    }
  }
      
  cout<<sum;

}
