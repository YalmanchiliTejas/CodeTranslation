#include<bits/stdc++.h>
using namespace std;

int main(){
  int A; int B; int C; int X; int Y;
  cin >> A >> B >> C >> X >> Y;
  //long ans=(A+B+C)*(X+Y); 
  long ans=(A+B+C)*(X+Y)+1000000000000; 
  long temp;
  
  int Z=max(X,Y);
  for(int  i=0; i < Z+1; i++){
    temp = max(0,X-i)*A +max(0,Y-i)*B + 2*i*C;
    ans=min(ans,temp);
  }
  
  cout << ans << endl;
}