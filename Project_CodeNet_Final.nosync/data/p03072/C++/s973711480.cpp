#include <bits/stdc++.h>
using namespace std;


int main() {
int N;
  cin>>N;
  
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec[i];}
  int MAX=vec[0];
  int counter=0;
  for(int i=0;i<N;i++){
    MAX=(max(MAX,vec[i]));
         if(MAX==vec[i]){
           counter++;
         }
         }
         
  
  
  cout<<counter<<endl;
  

}
