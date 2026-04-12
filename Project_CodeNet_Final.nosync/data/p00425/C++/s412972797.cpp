#include<iostream>
#include<string>
using namespace std;
int main(){
  int n, i;
  string s;
  while(cin >> n,n){
    int sum = 1;
    int a=1, b=2, c=3, d=5, e=4, f=6, x;
    for(int j= 0; j<n; j++){
      cin >> s;
      if(s=="North"){x=a; a=b; b=f; f=d; d=x;}
      else if(s=="East"){x=a; a=e; e=f; f=c; c=x;}
      else if(s=="West"){x=a; a=c; c=f; f=e; e=x;}
      else if (s== "South"){x=a; a=d; d=f; f=b; b=x;}
      else if(s=="Right"){x=b; b=c; c=d; d=e; e=x;}
      else {x=d; d=c; c=b; b=e; e=x;}
      //cout<<a<<b<<c<<d<<e<<f<<endl;
      sum += a;
    }
    cout<<sum <<endl;
  }
  return 0;
}