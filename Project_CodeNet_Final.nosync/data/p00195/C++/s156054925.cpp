#include <iostream>
#include <algorithm>
using namespace std;
int main(){

  int a[5],a1,a2,i,j;

  while(cin>>a1>>a2,a1){

    int b[5]={0,1,2,3,4};
    a[0]=a1+a2;
    for(i=1;i<5;i++){
      cin>>a1>>a2;
      a[i]=a1+a2;
    }

    for(i=0;i<4;i++){
      for(j=0;j<4;j++){
        if(a[j]<a[j+1]){
            int blank;
            blank=a[j];
            a[j]=a[j+1];
            a[j+1]=blank;
            blank=b[j];
            b[j]=b[j+1];
            b[j+1]=blank;
        }
      }
    }
    char team;
    team='A'+b[0];
    cout<<team<<" "<<a[0]<<endl;

  }

  return 0;


}
          
    
      