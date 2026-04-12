#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
  cout<<min(a*x+b*y,min(2*c*x+b*max(y-x,0),2*c*y+a*max(x-y,0)));
  
}

/*


*/