#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int AA=0;
  int BB=0;
  cin>>N;
  vector<long long>vec(N);
  vector<long long>A(0);
  vector<long long>B(0);
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
    if(X%2==0){
      A.push_back(vec.at(X));
    }
    else{
      B.push_back(vec.at(X));
    }
  }
  if(N%2==0){
    for(int X=B.size()-1;X>=0;X--){
      if(X==0){
        cout<<B.at(X)<<" ";
      }
      else{
        cout<<B.at(X)<<" ";
      }
    }
    for(int X=0;X<A.size();X++){
      if(X==N-1){
        cout<<A.at(X)<<endl;
      }
      else{
        cout<<A.at(X)<<" ";
      }
    }
  }
  if(N%2==1){
    for(int X=A.size()-1;X>=0;X--){
      if(X==0){
        cout<<A.at(X)<<" ";
      }
      else{
        cout<<A.at(X)<<" ";
      }
    }
    for(int X=0;X<B.size();X++){
      if(X==N-1){
        cout<<B.at(X)<<endl;
      }
      else{
        cout<<B.at(X)<<" ";
      }
    }
  }
}