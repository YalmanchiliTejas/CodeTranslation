#include <iostream>
using namespace std;
int main(){
     int N;
     cin>>N;
     int maxv=0;
     int sum=0;
     for(int i=0;i<N;i++){
         int H;
         cin>>H;
         if(i==0){
             maxv=H;
             sum++;
             continue;
         }
         if(maxv<=H){
             if(maxv==H){
                 sum++;
             }
             else if(maxv<H){
                 sum++;
                 maxv=H;
             }
         
     }
   
}
  cout<<sum<<endl;
}