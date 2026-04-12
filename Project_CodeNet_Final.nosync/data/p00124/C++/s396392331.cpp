#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, string> c;
vector<c> V;

bool compare(c x,c y) {
  return x.first<y.first;
}

int main() {
  int N;
  cin >> N;
  while(1) {
    if(N == 0) break;
    for(int i=0;i<N;i++) {
      int win,lose,draw,point;
      string country;
      cin >> country >> win >> lose >> draw;
      point = win * 3 + draw * 1;
      c temp;
      temp.first = point;
      temp.second = country;
      V.push_back(temp);
    }
    stable_sort(V.rbegin(), V.rend(), compare);

    for(int i=0;i<N;i++) {
      cout << V[i].second << "," << V[i].first << endl;
    }
    N=0;
    cin >> N;
    if(N == 0) break;
    else cout << endl;
    V.clear();
  }
}