  #include<iostream>
#include<string>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int truee[a];
  int truea[b];
  for(int i=0;i<a;i++) truee[i] = 0;
  for(int i=0;i<b;i++) truea[i] = 0;
  string g[a];
  for(int y=0;y<a;y++){
      cin>>g[y];
  }
  for(int i=0;i<a;i++){
    for(int h=0;h<b;h++){
      if(g[i][h]=='#') {
        truee[i]=1;
        truea[h]=1;
      }
    }
  }
    for(int i=0;i<a;i++){
      if(truee[i]){
        for(int h=0;h<b;h++){
        if(truea[h]) cout<<g[i][h];
        }
                      cout<<endl;
      }
    }
}
  