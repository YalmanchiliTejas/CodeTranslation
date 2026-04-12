#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> v(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for (int j=0;j<w;j++){
      cin>>v.at(i).at(j);
    }
  }
  for(int i=0;i<h;i++){
    int c=0;
    for(int j=0;j<w;j++){
      if(v.at(i).at(j)=='#'){
        c++;
      }
    }
    if(c==0){
      for(int j=0;j<w;j++){
        v.at(i).at(j)=' ';
      }
    }
  }
  for(int j=0;j<w;j++){
    int c=0;
    for(int l=0;l<h;l++){
      if(v.at(l).at(j)=='#'){
        c++;
      }
    }
    if(c==0){
      for(int l=0;l<h;l++){
        v.at(l).at(j)=' ';
      }
    }
  }
  for(int m=0;m<h;m++){
    int count=0;
    for(int p=0;p<w;p++){
      if(v.at(m).at(p)==' '){
        count++;
      }
    }
    if(count!=w){
      for(int n=0;n<w-1;n++){
      if(v.at(m).at(n)=='#'){
         cout<<"#";
      }
      else if(v.at(m).at(n)=='.'){
        cout<<".";
      }
    }
    if(v.at(m).at(w-1)=='#'){
         cout<<"#"<<endl;
    }
    else if(v.at(m).at(w-1)=='.'){
        cout<<"."<<endl;
    }
    else if(v.at(m).at(w-1)==' '){
      cout<<endl;
    }
    }
  }
}
