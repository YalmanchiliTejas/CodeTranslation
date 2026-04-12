#include<iostream>
#include<string>
using namespace std;

int main(void){
  int a6,
      a5,
  a4, a1, a3,
      a2;
  string str;
  int n, temp;
  while(cin >> n, n != 0){
    a1 = 1;
    a2 = 2;
    a3 = 3;
    a4 = 4;
    a5 = 5;
    a6 = 6;
    int ans = 1;
    for(int i = 0; i < n; i++){
      cin >> str;
      if(str == "North"){
	temp = a1;
	a1 = a2;
	a2 = a6;
	a6 = a5;
	a5 = temp;
      }
      if(str == "East"){
	temp = a1;
	a1 = a4;
	a4 = a6;
	a6 = a3;
	a3 = temp;
      }
      if(str == "West"){
	temp = a1;
	a1 = a3;
	a3 = a6;
	a6 = a4;
	a4 = temp;
      }
      if(str == "South"){
	temp = a1;
	a1 = a5;
	a5 = a6;
	a6 = a2;
	a2 = temp;
      }
      if(str == "Right"){
	temp = a2;
	a2 = a3;
	a3 = a5;
	a5 = a4;
	a4 = temp;
      }
      if(str == "Left"){
	temp = a2;
	a2 = a4;
	a4 = a5;
	a5 = a3;
	a3 = temp;
      }
      ans += a1;
    }
    cout << ans << endl;
  }
  return 0;
}