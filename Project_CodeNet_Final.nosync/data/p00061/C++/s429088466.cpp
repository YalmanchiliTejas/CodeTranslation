#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#define PII pair<int,int>
#define MIS map<int,set<int>,greater<int> >
#define MII map<int,int>
using namespace std;
int main()
{
  int n,c;
  MIS m;
  for(;;){
    scanf("%d,%d", &n, &c);
    if(n == 0 && c == 0) break;
    m[c].insert(n);
  }
  MII l;
  n = 1;
  for(MIS::iterator it = m.begin(); it != m.end(); it++, n++){
    set<int>::iterator p = (*it).second.begin();
    while(p != (*it).second.end()){
      l[(*p)] = n;
      p++;
    }
  }
  while(cin >> n){
    cout << l[n] << endl;
  }
  return 0;
}