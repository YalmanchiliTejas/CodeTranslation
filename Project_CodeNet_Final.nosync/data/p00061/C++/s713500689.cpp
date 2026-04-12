// AOL Q.0061
// YAMADA Terushige 2013.4.3.
 
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int main(){
 
  int num,point;
  char c; 
  set<int,greater<int> > s;
  set<int,greater<int> >::iterator is;
  map<int,int> table;
  vector<int> data(100);

  while(cin >> num >> c >> point){
    if (num == 0 && point ==0) break;
    data[num]=point;
    s.insert(point);
  }

  int i = 0;
  for(is = s.begin();is != s.end();is++){
    table[*is] = ++i;
  }
 
  while(cin >> num){
    cout << table[ data[num] ] << endl;
  }
  return 0;
}
