#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> hight(N);
  for(int i=0;i<N;i++)
    cin>>hight.at(i);
  
  int count=1;
  int R=0;
  for(int i=1;i<N;i++){
    for(int j=0;j<i;j++){
    	if(hight.at(j)<=hight.at(i))
          R++;
    }
    if(R==i)
      count++;
    R=0;
  }
  
  cout<<count<<endl;
}