#include<iostream>

using namespace std;

main(){
  int a,b,c;
  cin>>a>>b>>c;
  int d = b+c;
  int f = a/d;
  int g = a%d;
  
  if (g>=c) cout<< f <<endl;
  else cout<<f-1<<endl;
  return 0;
}