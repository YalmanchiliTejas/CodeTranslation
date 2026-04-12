#include <bits/stdc++.h>
using namespace std;
signed main(){
  int n=0;
  bool f=false;
  string c="\0";
  cin>>c;
  while(c[n+1] != '\0'){
    if(c[n] == 'A' && c[n+1] == 'C')
      f=true;
    n++;
  }
  if(f)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return(0);
}
  
