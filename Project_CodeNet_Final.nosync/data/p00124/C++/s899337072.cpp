#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Country{string name; int wp;};
vector<Country> Allteam;

bool comp(const Country& c1, const Country& c2){
  return (c1.wp > c2.wp);
}

int main(void){
  int n, k = 0;
  while(cin >> n, n){
    if(k != 0) cout << endl;
    for(int i = 0; i < n; i++){
      string tname;
      int w, l, d;
      cin >> tname >> w >> l >> d;
      Country c = {tname, w * 3 + d};
      Allteam.push_back(c);
    }
    sort(Allteam.begin(), Allteam.end(), comp);
    for(int i = 0; i < Allteam.size(); i++){
      cout << Allteam[i].name << "," << Allteam[i].wp << endl;
    }
    Allteam.clear();
    k++;
  }
  return 0;
}