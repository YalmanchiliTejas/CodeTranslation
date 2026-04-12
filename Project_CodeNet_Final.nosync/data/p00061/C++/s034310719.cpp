#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

int main() {
  int a, b, i;
  vector<pair <int, int> > p;
  while(~scanf("%d,%d", &a, &b), a != 0 || b  != 0)  {
    p.push_back(pair<int, int>(b,a));
  }
  
  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  
  while(cin >> a)  {
    i = 0;
    int bef = p[0].first;
    int rank = 1;
    
    while(1) {
      if(bef != p[i].first) {
	bef = p[i].first;
	rank++;
      }
      if(p[i++].second == a) break;
    }
      
    cout << rank << endl;
  }
  
  return 0;
}
  