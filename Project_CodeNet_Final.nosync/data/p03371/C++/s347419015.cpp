#include<bits/stdc++.h>
using namespace std;


int main(){
  long long a,b,c,x,y,ans;
  cin >>a>>b>>c>>x>>y;

  for(int i=0;i<=max(x,y);i++){
    int p=x-i;
    int q=y-i;
    if(i==0){
      ans = a*(x-i)+b*(y-i)+c*2*i;
    }
    if(a*max(0,p)+b*max(0,q)+c*2*i <=ans){
      ans =a*max(0,p)+b*max(0,q)+c*2*i;
    }

  }
  cout <<ans <<endl;
}
