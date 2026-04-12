#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;
typedef long long ll;

int main(){
  int a,b,c; cin>>a>>b>>c;
  int pi; pi = 100*a+10*b+c;
  if(pi%4==0){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }

}