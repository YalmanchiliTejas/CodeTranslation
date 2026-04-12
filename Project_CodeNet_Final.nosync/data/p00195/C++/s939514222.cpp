#include<iostream>
using namespace std;
int main(){
int a, b, c;
  char s;
  while(true)
  {
    cin >> a >> b;
    if(!a && !b)
      break;
    c = a + b;
    s = 'A';
    for(int i = 0; i < 4; i++)
    {
      cin >> a >> b;
      if(a + b > c)
      {
        c = a + b;
    s = 'B' + i;
      }
    }
    cout << s << " " << c << endl;
  }
	return 0;
}