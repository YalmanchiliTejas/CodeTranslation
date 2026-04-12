#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  sort(A.begin(),A.end());
  int64_t ans=0;
  if(N%2==0){
  for(int i=0;i<(N/2)-1;i++)
    ans+=(-2*A.at(i));
    ans-=A.at((N/2)-1);
    ans+=A.at(N/2);
    for(int i=1+(N/2);i<N;i++)
      ans+=2*A.at(i);
    cout<<ans<<endl;
    
  }else{
  for(int i=0;i<(N/2)-1;i++)
    ans+=(-2*A.at(i));
    ans-=A.at((N/2)-1);
    ans-=A.at(N/2);
    for(int i=1+(N/2);i<N;i++)
      ans+=2*A.at(i);
    if(0<(2*A.at(N/2)-A.at(1+(N/2))-A.at((N/2)-1)))
    ans+=(2*A.at(N/2)-A.at((N/2)+1)-A.at((N/2)-1));
    cout<<ans<<endl;
  
  }
   return 0;
}