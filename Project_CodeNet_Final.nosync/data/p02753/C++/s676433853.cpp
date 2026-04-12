
// C++ program for implementation of Ford Fulkerson algorithm 
#include <iostream> 
#include <limits.h> 
#include <string.h> 
#include <queue> 
#include <set>
using namespace std; 

#include <stdio.h>

int main(int argc, char *argv[]) {
   int tot;
   
   set<char>k;

   char* inp=new char[5];
    while(cin>>inp)
   {
     while(*inp!='\0')
     {
       k.insert(*inp);
       ++inp;
     }
     if(k.size()==1){
        cout<<"No";
        
     }else{
        cout<<"Yes";
     }
     k.clear();


   } 



   return(0);
}
   
