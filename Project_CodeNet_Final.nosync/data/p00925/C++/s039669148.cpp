#include<iostream>

using namespace std;

int main(){
  char e[99];
  cin>>e;
  int fr=e[0]-'0';
  int ba=0,bm=fr;
  for(char *p=e+1;*p;p+=2){
    int nd=p[1]-'0';
    if(*p=='+'){
      fr+=nd;
      ba+=bm;
      bm=nd;
    }else{
      fr*=nd;
      bm*=nd;
    }
  }
  int r;
  cin>>r;
  cout<<"IMLU"[(fr==r)*2+(ba+bm==r)]<<endl;
}