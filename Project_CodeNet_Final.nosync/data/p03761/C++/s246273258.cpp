#include <bits/stdc++.h>
using namespace std;





int main() {

  int n;
  cin>>n;
  
  vector<vector<int>> data(26,vector<int>(n,0));
  
  for (int i=0;i<n;i++){
    
    string si;
    
    cin>>si;
    
    int size=int(si.size());
    
    for (int j=0;j<26;j++){
      
      int count=0;
      
      for (int k=0;k<size;k++){
        if (si.at(k)==(char)('a'+j)){
          count++;
        }
      }
      
      data.at(j).at(i)=count;
    }
  }
  
  for (int i=0;i<26;i++){
    sort(data.at(i).begin(),data.at(i).end());
    int tmp;
    tmp=data.at(i).at(0);
    
    for (int k=0;k<tmp;k++){
      cout<<(char)('a'+i);
    }
  }
  
  cout<<endl;
  
     
    
}










