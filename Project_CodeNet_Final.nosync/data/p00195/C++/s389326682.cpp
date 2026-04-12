#include <iostream>
#include <vector>
#include <map>
#include <functional>
using namespace std;

int main(){
  int tmp,tmp2;
  while(1){
    map <int,char,greater<int> > pi;
    map <int,char,greater<int> >::iterator itr;
    for(int i=0;i<5;i++){
      cin >> tmp >> tmp2;
      if(tmp == 0 && tmp2 == 0) return 0;
      pi.insert(map<int,char,greater<int> >::value_type(make_pair(tmp+tmp2,i+'A')));
    }
    itr = pi.begin();
    cout << itr->second << " " << itr->first << endl;
  }
}