#include<iostream>
#include<algorithm>
using namespace std;
int main(){
      char str[6];
      for(int i=0;i<5;i++){cin>>str[i];}
      for(int i=0;i<5;i++){
        if(str[i]=='A'&&str[i+1]=='C'){
          cout<<"Yes"<<endl;
          return 0;
        }
       
        
      }
cout<<"No"<<endl;return 0;
}
  