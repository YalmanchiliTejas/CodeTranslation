#include <iostream>
using namespace std;

int main(){
  int a,b,d[110],e[110];
    cin>>a>>b;
   char c[110][110];
   for(int i =0;i<a ;i++){
      d[i] =0;
   }
  for(int j =0;j<b;j++){
     e[j] =0;
  }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>c[i][j];
            if(c[i][j]=='#'){
                d[i]=1; e[j]=1;
            }
        }
    }
    for(int i=0;i<a;i++){
        if(d[i] == 0) 
          continue;
        for(int j=0;j<b;j++){
            if(e[j] ==0 ) 
              continue;
          
            cout<<c[i][j];
        }
        cout<<endl;
    }
}
