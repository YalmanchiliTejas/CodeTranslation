#include<bits/stdc++.h>
using namespace std;

int main(){
  
  string S_, Ans="";
  int n;
  map<string, int> S;
  cin>>n;
  
  for(int i=0; i<n; i++){
    cin>>S_;
    sort(S_.begin(), S_.end());
    
    for(int j=0; j<(int)S_.size(); j++){
      
      int l=1;
      do{
        S[S_.substr(j, l)]++;
        l++;
        if(j+l-1>=(int)S_.size()) break;
      }while(S_[j]==S_[j+l-1]);
      j+=l-2;
    }
  }
  
  for(auto it=rbegin(S); it!=rend(S); it++){
    
    if(it->second==n){
      Ans+=it->first;
      advance(it, it->first.size()-1);
    }
  }
  reverse(Ans.begin(), Ans.end());
  cout<<Ans<<endl;
  return 0;
}