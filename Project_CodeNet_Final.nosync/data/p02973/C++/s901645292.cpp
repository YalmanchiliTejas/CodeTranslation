#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  vector<int> num(n);
  for(int i=0;i<n;i++){
    cin>>num[i];
  }
  vector<int> col(1);
  int mx=num[n-1];
  col[0]=num[n-1];
  for(int i=n-2;i>=0;i--){
    if(mx>num[i]){
      auto itr=upper_bound(col.begin(),col.end(),num[i]);
      int j=int(itr-col.begin());
      if(col[j]==mx && j==col.size()-1) mx=num[i];
      col[j]=num[i];
    }else{
      col.push_back(num[i]);
      mx=num[i];
    }
  }  
  cout<<col.size()<<endl;
}     