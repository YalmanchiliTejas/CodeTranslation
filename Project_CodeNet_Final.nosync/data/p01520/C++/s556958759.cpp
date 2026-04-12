
#include<iostream>
using namespace std;

int main()
{
  int N,T,E;
  int x;
  int ans=-1;
  cin>>N>>T>>E;
  for(int i=0;i<N;i++){
    cin>>x;
    int t=T/x;
    for(int t=x;t<=T+E;t+=x){
      if(t<T-E)continue;
      ans=i+1;
    }
  }
  cout<<ans<<endl;
}