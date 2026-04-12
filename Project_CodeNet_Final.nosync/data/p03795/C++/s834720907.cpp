#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin>>n;
  
  int answer=0;
  for(int i=1; i<=n; i++){
    answer+=800;
    if(i%15==0){
      answer-=200;
    }

  }

  cout<<answer<<endl;
}
