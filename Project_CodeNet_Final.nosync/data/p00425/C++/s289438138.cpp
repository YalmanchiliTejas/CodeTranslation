#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){

  int m,tmp;

  while(cin >> m, m){
    int f = 1,s = 2,e = 3,w = 4,n = 5,b = 6;
    int ans = 0;

    for(int i=0;i<m;i++){
      string str;
      cin >> str;

      if(str == "North"){
	tmp = f;
	f = s;
	s = b;
	b = n;
	n = tmp;
      }

      else if(str == "East"){
	tmp = f;
	f = w;
	w = b;
	b = e;
	e = tmp;
      }

      else if(str == "West"){
	tmp = f;
	f = e;
	e = b;
	b = w;
	w = tmp;
      }

      else if(str == "South"){
	tmp = f;
	f = n;
	n = b;
	b = s;
	s = tmp;
      }

      else if(str == "Right"){
	tmp = s;
	s = e;
	e = n;
	n = w;
	w = tmp;
      }

      else if(str == "Left"){
	tmp = s;
	s = w;
	w = n;
	n = e;
	e = tmp;
      }
      ans += f;    
    }

    cout << ans+1 << endl;

  }
}