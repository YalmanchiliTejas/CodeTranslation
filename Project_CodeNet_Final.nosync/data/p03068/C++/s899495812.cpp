#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin>>N;
  string str;
  cin>>str;
  int K;
  cin>>K;
  for (int i = 0; i < N; i++) {
  if(str.at(i)==str.at(K-1)){
    cout<<str.at(i);}
      else{
        cout<<"*";
}
  }
}