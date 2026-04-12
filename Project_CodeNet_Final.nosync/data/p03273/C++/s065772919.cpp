#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w,ig[100],icnt=0;
  char sp[100][100];
  cin>>h>>w;
  for(int i=0; i<h; i++){
    bool alldot=true;
    for(int j=0; j<w; j++){
      cin>>sp[i][j];
      if(sp[i][j]!='.') alldot=false; 
    }
    if(alldot){
      h--;
      i--;
      continue;
    }
  }
  for(int j=0; j<w; j++){
    bool alldot=true;
    for(int i=0; i<h; i++){
      if(sp[i][j]!='.'){ alldot=false;}
    }
    if(alldot){
      ig[icnt]=j;
      icnt++;
      // continue;
    }
  }
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      bool isok=true;
      for(int k=0; k<icnt; k++){
	if(ig[k]==j)isok=false;
      }
      if(isok)cout<<sp[i][j];
    }
    cout<<endl;
  }
}

