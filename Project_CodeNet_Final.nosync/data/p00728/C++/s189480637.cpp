#include<iostream>

using namespace std;

int main(){
  int n,i,p,max,min,s;

    while(1){
      cin>> n;
      if(n){}else break;
      
      cin>> p;
      s = p;
      max = p;
      min = p;

      for(i = 0 ; i < n-1 ;i++){
          cin>> p;
          s += p;
          if(max < p){
              max = p;
	  }
          if(min > p){
              min = p;
	  }
      }
      s = (s - max - min)/ (n-2);
      cout<< s << endl;
  }    
  return 0;
} 