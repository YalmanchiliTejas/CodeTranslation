#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,i,j,count;

  cin>>N;
  vector<int> h(N);
  for(i=0;i<N;i++)
  cin>>h.at(i);

  count=1;

  for(i=1;i<N;i++){
    for(j=0;j<i;j++){
      if(h.at(i)>=h.at(j)){
        if(j==i-1)
        count++;
        continue;
      }
      else
      break;
    }
  }

  cout<<count<<endl;
}
