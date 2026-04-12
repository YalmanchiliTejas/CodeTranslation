#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  std::vector<int> v(N),b(N);
  for(int i=0;i<N;i++)cin>>v[i];
  if(N%2==0){
    for(int i=0;i<N;i++){
      if(i%2==0)b[N/2+i/2]=i;
      else b[N/2-i/2-1]=i;
    }
  }
  else{
    for(int i=0;i<N;i++){
      if(i%2==0)b[N/2-i/2]=i;
      else b[N/2+i/2+1]=i;
    }
  }
  for(int i=0;i<N;i++)cout<<v[b[i]]<<" ";
  cout<<endl;
}
