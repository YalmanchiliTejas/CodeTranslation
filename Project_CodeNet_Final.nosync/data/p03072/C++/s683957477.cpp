#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int b=0,h,N,A=1;
  cin>>N;
  vector<int> a(N);
  for(int i=0;i<N;i++){cin>>a.at(i);}
  for(int i=1;i<N;i++){
    if(b==1){
      if(h<=a.at(i)){A++;b=0;}
    }
    else {if(a.at(i-1)<=a.at(i)){A++;}
    else{
      h=a.at(i-1);
      b=1;
    }}
  }
  cout<<A<<endl;
}
