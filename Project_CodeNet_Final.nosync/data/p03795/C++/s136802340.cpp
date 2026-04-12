#include<iostream>

using namespace std;

int main(void)
{
  int N;
  
  cin>>N;
  
  int exc=200*(N/15);
  
  int ans=800*N-exc;
  
  cout<<ans<<endl;
  
}