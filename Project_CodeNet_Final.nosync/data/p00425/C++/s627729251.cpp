#include <iostream>
#include <string>

using namespace std;


int main() {

  int n;
  string buf;

  int a,b,c;
  int sum;

  
  while(cin >> n,n) {

    sum=1;

    a=1;
    b=2;   
    c=3;

    for(int i=0;i<n;i++) {

      int tmp;

      cin >> buf;

      if(buf=="North") {

	tmp=a;
	a=b;
	b=7-tmp;
      
      }

      else if(buf=="East") {

	tmp=c;
	c=a;
	a=7-tmp;

      }

      else if(buf=="West") {

	tmp=a;
	a=c;
	c=7-tmp;

      }

      else if(buf=="South") {

	tmp=b;
	b=a;
	a=7-tmp;

      }

      else if(buf=="Right") {

	tmp=b;
	b=c;
	c=7-tmp;

      }

      else if(buf=="Left") {

	tmp=c;
	c=b;
	b=7-tmp;

      }

      sum+=a;

    }

    cout << sum << endl;

  }

  return 0;

}