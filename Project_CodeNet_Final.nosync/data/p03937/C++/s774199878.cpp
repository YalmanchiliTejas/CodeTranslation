#include<iostream>
#include<string>
int main(){
  int H,W;
  std::cin>>H>>W;
  std::string str[H];
  for(int i=0;i<H;i++){
    std::cin>>str[i];
  }
  int cont,place=0;
  for(int i=0;i<H;i++){
    cont=0;
    for(int j=0;j<W;j++){
      if(str[i][j]=='#'&&cont!=-1){
        if(place>j){
          std::cout<<"Impossible"<<std::endl;
          return 0;
        }
        cont=1;
        place=j;
      }else if(cont==1&&str[i][j]=='.'){
        cont=-1;
      }else if(cont==-1&&str[i][j]=='#'){
        std::cout<<"Impossible"<<std::endl;
        return 0;
      }
    }
  }
  std::cout<<"Possible"<<std::endl;
  return 0;
}