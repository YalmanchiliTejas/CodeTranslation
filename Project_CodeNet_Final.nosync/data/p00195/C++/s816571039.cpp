#include<iostream>
#include<string>
using namespace std;

int main(){
  string shop[5]={"A","B","C","D","E"};
  string ans_char;
  int mo,af,ans_int;
  while(1){
    cin >> mo >> af;
    if(mo == 0 && af == 0) break;
    ans_int = mo + af;
    ans_char = shop[0];
    for(int i=1;i<=4;i++){
      cin >> mo >> af;
      if(ans_int < mo + af){
	ans_int = mo + af;
	ans_char = shop[i];
      }
    }
    cout << ans_char << " " << ans_int << endl;
  }
}