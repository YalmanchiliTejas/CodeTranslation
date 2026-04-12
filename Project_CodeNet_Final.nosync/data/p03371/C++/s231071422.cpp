#include<bits/stdc++.h>
using namespace std;
int main(){
  long long A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  long long Ans1=A*X+B*Y;
  long long Ans2;
  if(X<=Y){
    Ans2=(Y-X)*B+C*2*X;
  }
  else{
    Ans2=(X-Y)*A+C*2*Y;
  }
  long long Ans3=C*max(X,Y)*2;
  cout<<min(Ans1,min(Ans2,Ans3))<<endl;
}
  
