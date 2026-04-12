#include<bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin>>H>>W;
  vector<string>vec(H);
  for(int i=0;i<H;i++){
    cin>>vec.at(i);
  }
  for(int i=0;i<H;i++){
    bool frag1=true;
    for(int j=0;j<W;j++){
      if(vec.at(i).at(j)=='#'){
        frag1=false;
      }
      else{
      }
    }
    if(frag1==true){
      for(int k=0;k<W;k++){
        vec.at(i).at(k)='0';
      }
    }
    else{
    }
  }
  for(int i=0;i<W;i++){
    bool flag=true;
    for(int j=0;j<H;j++){
      if(vec.at(j).at(i)=='#'){
        flag=false;
      }
      else{
      }
    }
    if(flag==true){
      for(int k=0;k<H;k++){
        vec.at(k).at(i)='0';
      }
    }
    else{
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(vec.at(i).at(j)=='0'){
      }
      else{
        cout<<vec.at(i).at(j);
      }
    }
    cout<<' '<<endl;
  }
}
