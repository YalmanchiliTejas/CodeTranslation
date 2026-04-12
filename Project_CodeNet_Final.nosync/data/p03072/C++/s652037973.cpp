#include <iostream>
using namespace std;
int main(void){
   int N,T,h;
   cin>>N;
   T=1;
   int H[N];
   for(int i=0;i<N;i++){
       cin>>H[i];
    }
    h=H[0];
    
    for(int i=0;i<N-1;i++){
        
        if(h<=H[i+1]){
           T=T+1;
           h=H[i+1];
           
       }
      
    }
   
   cout<<T<<endl;
   return 0;
}