#include <iostream>
#include <string>
using namespace std;
bool a[] = {
  true,true,true,true,true,true,true,false,false,false,false,false,false,
  false,false,false,true,true,true,true,false,true,true,true,false,true,
};
int main()
{
  string s;
  int c,i;
  bool b;
  while(cin >> s, s != "#"){
    b = a[s[0]-'a'];
    c = 0;
    for(i=1;i<s.length();i++){
      if(b != a[s[i]-'a']){
	c++;
	b = a[s[i]-'a'];
      }
    }
    cout << c << endl;
  }
  return 0;
}