#include <bits/stdc++.h>
using namespace std;

long long b[100];

long long c[100];

long long  a( long long k) {
     if (k==0){
	    
	    return 1;
	 }
	 else {
	    return 2*a(k-1)+3;
	 }
	 
} 

long long  p(long long y){
     if(y==0){
	    return 1;
	 }
	 else {
	    return 2*p(y-1)+1; 
	 }
}

long long res (long long m , long long n){


     if(m==0){
       if(n==0)return 0;
	   else {
	      return 1;
	   }	  
     }   
	 else { 
            if(n==0) return 0;
	 		else if(n>=1&&n<=b[m-1]+1) return res(m-1,n-1);
	        else if(n==b[m-1]+2) return res(m-1,n-2)+1;
            else if(n>=b[m-1]+3) return c[m-1]+1+res(m-1,n-b[m-1]-2);  
	 }

}



int main() {
  int N;
  cin >> N;
  
  long long X;
  cin >> X;
  
  
  for(int i=0 ;i<N;i++){
      b[i]=a(i);
	  c[i]=p(i);
  }
  
  
  long long  r;
  
  r=res(N,X);
  
  
  
  cout << r << endl ;
  
}

