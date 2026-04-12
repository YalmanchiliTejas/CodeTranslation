#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  d=0;
  c=0;
  cin >> a;
  for(int i=0;i<a;i++){
  	cin>>b;
    if(b>=c){
      c = b;
      d++;
    }
  }
  cout<<d<<endl;
}