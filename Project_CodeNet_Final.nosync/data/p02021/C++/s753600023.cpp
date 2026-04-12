#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin>>N;

  vector<int> A;
  int sum = 0;
  for(int i = 0;i < N;++i){
    int temp;
    cin>>temp;
    A.push_back(temp);
    sum += temp;
  }

  int day = sum / N;
  while(1){
    int c = 0;
    int a = 0;
    for(int e : A){
      c = (c + e) - day;
      if(c < 0){
        --day;
        a = 1;
        break; 
      } 
    }
    if(a == 0){
      break;
    }
    else{
      a = 0;
    }
  }

  cout<<day<<endl;

  return 0;
}
