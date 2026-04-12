#include<iostream>
#include<string>
using namespace std;

int main(){
  int i, n, u=1, f=2, r=3, s, sum=1;
  string com;

  while(1){
    cin >> n;
    if (n == 0) break;

    for (i=0; i<n; i++){
      cin >> com;
      if (com == "North"){
	s=u; u=f; f=7-s;
      } else if (com == "East"){
	s=r; r=u; u=7-s;
      } else if (com == "West"){
	s=u; u=r; r=7-s;
      } else if (com == "South"){
	s=f; f=u; u=7-s;
      } else if (com == "Right"){
	s=f; f=r; r=7-s;
      } else {
	s=r; r=f; f=7-s;
      }

      sum += u;
    }

    cout << sum << endl;
    u=1; f=2; r=3; sum=1;
  }

  return 0;
}

	