#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  long int minp=A*X+B*Y;
  for(int c=2;c<=max(2*X,2*Y);c+=2){
    long int p=A*max(0,(X-c/2))+B*max(0,(Y-c/2))+C*c;
    minp=min(minp,p);
  }
  cout<<minp<<endl;
}
