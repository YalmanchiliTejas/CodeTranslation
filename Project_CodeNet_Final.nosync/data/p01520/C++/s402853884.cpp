//16
#include<iostream>

using namespace std;

int main(){
  int n,t,e;
  cin>>n>>t>>e;
  for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    int s=t/x;
    if(t-s*x<=e||(s+1)*x-t<=e){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}