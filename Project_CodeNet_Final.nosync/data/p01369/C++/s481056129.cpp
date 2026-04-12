#include<iostream>
#include<string>
using namespace std;

int main(){

  string l = "qwertasdfgzxcvb";
  string r = "yuiophjklnm";
  string str;

  while(cin >> str){
    if(str == "#") break;

    int x = 0,y = 0,a = -1;

    for(int i=0;i<str.size();i++){

      for(int j=0;j<=15;j++){
	if(l[j] == str[i]){
	  if(a == 1) x++;
	  a = 0;
	}
      }

      for(int j=0;j<=11;j++){
	if(r[j] == str[i]){
	  if(a == 0) x++;
	  a = 1;
	}
      }
    }
    cout << x << endl;

  }
}