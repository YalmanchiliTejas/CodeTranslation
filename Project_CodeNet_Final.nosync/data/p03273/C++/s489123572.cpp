#include <iostream>
using namespace std;


int main(void){
    
   int h,w;
   string s[111];
   cin>>h>>w;
   for(int i=0;i<h;i++)cin>>s[i];
   for(int i=0;i<h;i++){
       int co=0;
       for(int j=0;j<w;j++){
           if(s[i][j]=='.')co++;
       }
       if(co==w){
          for(int j=0;j<w;j++)s[i][j]='0'; 
       }
   }
   for(int j=0;j<w;j++){ 
       int co=0;
       for(int i=0;i<h;i++){
           if(s[i][j]=='.'|| s[i][j]=='0')co++;
       }
       if(co==h){
          for(int i=0;i<h;i++)s[i][j]='0'; 
       }
   }
   for(int i=0;i<h;i++){
       int co=0;
       for(int j=0;j<w;j++){
          if(s[i][j]!='0')cout<<s[i][j];
          else co++;
       }
       if(co!=w)cout<<endl;
   }
 
}
