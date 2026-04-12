#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

int main(void){
 int A,B,C,X,Y;
 long long int sum=0;
 cin>>A>>B>>C;
 cin>>X>>Y;
 sum=A*(X-min(X,Y))+B*(Y-min(X,Y))+C*2*min(X,Y);
 if((A+B)<2*C)std::cout<<A*X+B*Y<<std::endl;
 else if(C*2*max(X,Y)<sum)std::cout<<C*2*max(X,Y)<<std::endl; 
 else std::cout<<sum<<std::endl;
}