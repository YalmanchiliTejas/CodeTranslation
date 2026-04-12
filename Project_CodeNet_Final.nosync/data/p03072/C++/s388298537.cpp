#include<iostream>
using namespace std;
int main(){
  int N;
  int *p;
  int ans=0,a=0;
  cin>>N;
  p=new int [N];
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  a=p[0];
  for(int i=0;i<N;i++){
    if(a<=p[i]){
      ans++;
      a=p[i];
    }
  }
  cout<<ans<<endl;
  
  return 0;
}