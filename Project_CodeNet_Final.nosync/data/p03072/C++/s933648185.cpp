#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const long long MOD=1e09+7;

#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>






int main(){
  

  int n;
  cin>>n;
  
  vi height(n);
  rep(i,n){
    int tmp;
    cin>>tmp;
    height.at(i)=tmp;
  }
  
  vi maxes(n);
  int tmp=height.at(0);
  maxes.at(0)=tmp;
  for (int i=1;i<n;i++){
    tmp=max(tmp,height.at(i));
    maxes.at(i)=tmp;
  }
  
  int answer=0;
  rep(i,n){
    if (height.at(i)==maxes.at(i)){
      answer++;
    }
  }
  
  cout<<answer<<endl;

    
      
 

  
}