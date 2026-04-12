#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;

int main(void){
  vector<PII> v;
  int p,s,q;
  char cmm; // to skip reading camma
  
  // regist
  while (cin >> p >> cmm >> s){
    if (p==0 && s==0) break;
    v.push_back(make_pair(s,p));
  }
  // sort by score (desc.)
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  // query
  while (cin >> q){
    int rnk=1;
    for (int i=0; i<v.size(); i++){
      if (i!=0 && v[i].first != v[i-1].first) rnk++;
      if (v[i].second == q){
        cout << rnk << endl;
        break;
      }
    }
  }
  return 0;
}
