#include<bits/stdc++.h> 
using namespace std; 

int main() { 
int n  ; 
scanf("%d" , &n) ; 

int x , y ,c=0  ;
  x=n*800;
  while (n>=15)
{ 
n-=15;
c++;
   }   

y=c*200;

printf("%d \n " , x-y );
return 0;
}