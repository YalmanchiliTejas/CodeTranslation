#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,X,Y;cin>>A>>B>>C>>X>>Y;
  int AB=C*2;
  long long H=1000000000;
  for(int L=0;L<=100000;L++){
    if(H>AB*L+A*max(0,X-L)+B*max(0,Y-L)){
      H=AB*L+A*max(0,X-L)+B*max(0,Y-L);
    }
  }
  cout<<H<<endl;
}