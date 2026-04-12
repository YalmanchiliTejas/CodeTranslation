#include <iostream>
#include <string>
#include <map>
#define V multimap<int,string>::value_type
using namespace std;
int main()
{
  int n,w,l,d;
  string s;
  bool p = false;
  for(;;){
    cin >> n;
    if(n == 0) break;
    if(p) cout << endl;
    multimap<int,string, greater<int> > m;
    while(n--){
      cin >> s >> w >> l >> d;
      m.insert( V(w*3+d*1,s) );
    }
    multimap<int,string>::iterator it = m.begin();
    while(it != m.end()){
      cout << (*it).second << "," << (*it).first << endl;
      it++;
    }
    p = true;
  }
  return 0;
}