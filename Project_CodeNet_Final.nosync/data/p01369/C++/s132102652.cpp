#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  while(1){
    int count=0;
    int flag[2]={0};
    string str;
    int temp;

    cin>>str;
    
    if(str[0]=='#'){
      str.clear();
      break;
    }

    for(int i=0;i<str.size();i++){
      if(('h'<=str[i] && str[i]<='p') || (str[i]=='u') || (str[i]=='y')){
        if(i>=1){
          flag[0]=flag[1];
        }
        flag[1]=1;
        if(((flag[1]-flag[0])==1) || ((flag[0]-flag[1])==1)){
          count++;
          if(i==0)
            count=0;
        }
      }
      else{
        if(i>=1){
          flag[0]=flag[1];
        }
        flag[1]=0;
        if(((flag[1]-flag[0])==1) || ((flag[0]-flag[1])==1)){
          count++;
          if(i==0)
            count=0;
        }
      }
    }

    cout<<count<<endl;

    str.clear();
  }
}

