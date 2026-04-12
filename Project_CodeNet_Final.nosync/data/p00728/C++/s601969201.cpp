#include <iostream>
using namespace std;


int main(){
  while(true){
    int n;
    cin>>n;
    if(n==0){
      break;
    }
    int avn=n-2,s[n],total=0;
    for(int k=0;k<n;k++){
      cin>>s[k];
      total=total+s[k];
    }
    int max=0,min=1000;
    for(int i=0;i<n;i++){
      if(s[i]>max){
	max=s[i];
      }
      if(s[i]<min){
	min=s[i];
      }
    }
    total=total-max-min;
    total=total/avn;
    cout<<total<<endl;
  }

  return 0;
}