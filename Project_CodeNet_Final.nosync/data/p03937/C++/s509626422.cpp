#include <iostream>

char field[10][10];
int H,W;

int main(){
   std::cin>>H>>W;
   int cnt=0;
   for(int i=0;i<H;++i){
       for(int j=0;j<W;++j){
           std::cin>>field[i][j];
           if(field[i][j]=='#')cnt++;
       }
   }
   if(cnt==H+W-1)std::cout<<"Possible"<<std::endl;
   else std::cout<<"Impossible"<<std::endl;
   return 0;
}