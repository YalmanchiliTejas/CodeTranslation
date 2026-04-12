#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<pair<int, int> > v;

int main()
{
  int h, w;
  cin >> h >> w;

  for(int i = 0; i < h; i++){
    string a;
    cin >> a;
    
    for(int j = 0; j < w; j++){
      if(a[j] == '#'){
        v.push_back(make_pair(i, j));
      }
    }
  }

  sort(v.begin(), v.end());

  for(int i = 1; i < v.size(); i++){
    if(v[i-1].second > v[i].second){
      cout << "Impossible" << endl;
      return 0;
    }
  }

  cout << "Possible" << endl;

  return 0;
}

