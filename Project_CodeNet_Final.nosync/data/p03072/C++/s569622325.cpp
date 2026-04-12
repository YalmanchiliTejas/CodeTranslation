#include <iostream>
using namespace std;

int main(){
 int n,i,j;
 int a[30];
 int num=0;
 cin>>n;
  num=n;
for(i=0;i<n;i++){
     cin>>a[i];
}
  
for(i=0;i<n;i++){
    for(j=0;j<i;j++){
        if(a[i]<a[j]){
            num--;
          	break;
        }
    }
}

cout<<num;

}

