#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string sou;
  char temp;
  int ans;
  int sugo[6];
  while(cin>>n){
    if(!n)break;
    ans=1;
    sugo[0]=1;
    sugo[1]=2;
    sugo[2]=3;
    sugo[3]=4;
    sugo[4]=5;
    sugo[5]=6;
      while(n--){
        cin>>sou;
        if(sou=="North"){
          temp=sugo[0];
          sugo[0]=sugo[1];
          sugo[1]=sugo[5];
          sugo[5]=sugo[4];
          sugo[4]=temp;
          ans+=sugo[0];
        }
        else if(sou=="East"){
          temp=sugo[0];
          sugo[0]=sugo[3];
          sugo[3]=sugo[5];
          sugo[5]=sugo[2];
          sugo[2]=temp;
          ans+=sugo[0];
        }
        else if(sou=="West"){
          temp=sugo[0];
          sugo[0]=sugo[2];
          sugo[2]=sugo[5];
          sugo[5]=sugo[3];
          sugo[3]=temp;
          ans+=sugo[0];
        }
        else if(sou=="South"){
          temp=sugo[0];
          sugo[0]=sugo[4];
          sugo[4]=sugo[5];
          sugo[5]=sugo[1];
          sugo[1]=temp;
          ans+=sugo[0];
        }
        else if(sou=="Right"){
          temp=sugo[1];
          sugo[1]=sugo[2];
          sugo[2]=sugo[4];
          sugo[4]=sugo[3];
          sugo[3]=temp;
          ans+=sugo[0];
        }
        else if(sou=="Left"){
          temp=sugo[1];
          sugo[1]=sugo[3];
          sugo[3]=sugo[4];
          sugo[4]=sugo[2];
          sugo[2]=temp;
          ans+=sugo[0];
        }
      }
      cout<<ans<<endl;
  }
}