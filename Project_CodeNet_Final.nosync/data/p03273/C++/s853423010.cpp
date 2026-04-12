#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  vector<string> data(h);
  vector<int> del;
  for(int i=0;i<h;i++){
   cin>>data.at(i);
  }
  for(int i=0;i<h;i++){
    int c=0;
    for(int j=0;j<w;j++){
      if(data.at(i).at(j)=='#')
        c=1;
    }
    if(c==0)
        del.push_back(i+1);
  }
  for(int i=0;i<w;i++){
    int c=0;
    for(int j=0;j<h;j++){
      if(data.at(j).at(i)=='#')
        c=1;
    }
    if(c==0)
        del.push_back(-(i+1));
  }
 int M=0;
  for(int x:del){
    if(x<0){
      for(int i=0;i<data.size();i++){
        if(data.at(i)!=""){
          data.at(i).erase(-(x+1+M),1);
          
        }
      }
      M++;
    }
    else{
      data.at(x-1).erase(0);
    }
  }
  for(int i=0;i<data.size();i++){
    if(data.at(i)!="")
    cout<<data.at(i)<<endl;
  }

}