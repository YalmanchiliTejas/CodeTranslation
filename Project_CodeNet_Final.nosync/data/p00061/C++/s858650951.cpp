#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

bool cmp(pii l, pii r){
  return (l.first > r.first);
}

int main()
{
  vector<pii> vpii;
  int a, b;
  while (scanf("%d,%d", &a, &b), a || b){
    vpii.push_back(make_pair(b, a));
  }
  sort(vpii.begin(), vpii.end(), cmp);
  map<int, int> mii;
  int j = 1;
  int m = vpii.size();
  for (int i = 0; i < m; i++){
    if (i != m - 1 && vpii[i].first == vpii[i + 1].first){
      mii[vpii[i].second] = j;
    }
    else {
      mii[vpii[i].second] = j++;
    }
  }

  int c;
  while(cin >> c){
    cout << mii[c] << "\n";
  }
}