#include <bits/stdc++.h>
using namespace std;

bool hor(vector<vector<char>> sign,int h,int w,int x){
  int sum=0;
  for(int i=0;i<w;i++){
    if(sign.at(x).at(i)!='.'){
      sum++;
      //cout<<sum;
    }
  }
  return sum!=0;
}
bool ver(vector<vector<char>> sign,int h,int w,int y){
  int sum=0;
  for(int i=0;i<h;i++){
    if(sign.at(i).at(y)!='.')
      sum++;    
  }
  return sum!=0;
}



int main(){
  int h,w;
  cin>>h>>w;
  
  vector<vector<char>> sign (h,vector<char>(w));
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++)
    {
      cin >> sign.at(i).at(j); 
      //cout<< sign.at(i).at(j);
    }
  }
  
  for(int i=0;i<h;i++){
    //cout<<i;
    //cout<<hor(sign,h,w,i)<<endl;
    if(hor(sign,h,w,i)){
      for(int j=0;j<w;j++){
        if(ver(sign,h,w,j))
          cout<<sign.at(i).at(j);
      }
      cout<<endl;
    }
  }
  
  
}