#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int countA=0,countB=0;
  long long sum=0;
  int mi,ch;
  mi=min(X,Y);
  while(true){
    if(countA<mi || countB<mi){
      if(A+B<2*C){
	sum+=A+B;
	countA++;
	countB++;
      }
      else{
	sum+=2*C;
	countA++;
	countB++;
      }
      if(countA==X && countB==Y) break;
    }
    else{
      if(mi==X){
	if(B<2*C){
	  sum+=B;
	  countB++;
	  
	}
	else{
	  sum+=2*C;
	  countB++;
      }
	if(countB==Y) break;

      }
      else{
	if(A<2*C){
	  sum+=A;
	  countA++;
	}
	else{
	  sum+=2*C;
	  countA++;
	}
	if(countA==X) break;

      }
    }
    //cout<<countB<<" "<<countA<<endl;
  }
  cout<<sum<<endl;
}
