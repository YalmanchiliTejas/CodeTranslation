#include<iostream>
using namespace std;
int main(){
  int most,a,b;
  char s,MOST;
  while(1){
    cin >> a >> b;
    if(a==0 && b==0){
      break;
    }
    s='A';
    most=a+b;
    MOST=s;
    for(int i=1;i<5;i++){
      cin >> a >> b;
      s++;
      if(a+b>most){
	most=a+b;
	MOST=s;
      }
    }
    cout << MOST << " " << most << endl;
  }
}