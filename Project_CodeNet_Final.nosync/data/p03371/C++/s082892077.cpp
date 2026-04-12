#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B,C,X,Y,large,abc,ac,bc;
  cin>>A>>B>>C>>X>>Y;
  
  large=max(X,Y);  
  vector<int> cost;
  
  for(int i=0;i<=large;i++){
    if(i==0)
      abc=1;
    else
      abc=i*2;
    ac=X-abc/2;
    if(ac<0)
      ac=0;
    bc=Y-abc/2;
    if(bc<0)
      bc=0;
    if(i==0)
      abc=0;
    cost.push_back(ac*A+bc*B+abc*C);
  }
  sort(cost.begin(),cost.end());
  cout <<cost.at(0)<<endl;
  
}
