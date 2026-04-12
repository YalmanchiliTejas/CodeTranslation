#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
 int N;
 cin >> N;
 int count = 0;
 int highest =0;
 int H;

 for(int i=0;i<N;i++){
   cin>> H;
   if(H>=highest){
     highest=H;
     count++;
   }
   } 
   
    
 
 
   
 
cout<< count <<endl;

  }
