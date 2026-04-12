#include <iostream>
#include <string>
using namespace std;

int N , t0 , tn , type[100000] ;
bool flag = false ; 
string s ;

void type_and_print(){
     if(flag) return ;
     
     for(int i=1;i<N;i++){
          if((type[i] == 1 && s[i] == 'o') || (type[i] == -1 && s[i] == 'x')){
               type[(i+1)%N] = type[i-1] ;
          }else{
               type[(i+1)%N] = -type[i-1] ;
          }
     }
     
     if(type[0] == t0 && type[N-1] == tn){
          
          flag = true ;
          
          for(int i=0;i<N;i++){
              if(type[i] == 1){
                   cout << 'S' ;
              }else{
                   cout << 'W' ;
              }
         }
        
     }
     
}

int main(void){
     
     cin >> N >> s ;
     
     if(s[0] == 'o'){
          type[0] = t0 = 1 ; type[1] = -1 ; tn = -1; 
          type_and_print() ;
          
          type[0] = t0 = 1 ; type[1] = 1 ; tn = 1 ; 
          type_and_print() ;
          
          type[0] = t0 = -1 ; type[1] = 1 ; tn = -1 ; 
          type_and_print() ;
          
          type[0] = t0 = -1 ; type[1] = -1 ; tn = 1 ; 
          type_and_print() ;
     }
     
    if(s[0] == 'x'){
          type[0] = t0 = -1 ; type[1] = 1 ; tn = 1 ;
          type_and_print() ;
          
          type[0] = t0 = 1 ; type[1] = -1 ; tn = 1 ; 
          type_and_print() ;
          
          type[0] = t0 = -1 ; type[1] = -1 ; tn = -1 ; 
          type_and_print() ;
          
          type[0] = t0 = 1 ; type[1] = 1 ; tn = -1 ; 
          type_and_print() ;
          
     }
     
     if(!flag) cout << -1 ;
}
