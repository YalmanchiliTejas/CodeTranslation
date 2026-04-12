#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;

template< typename T >
typename std::vector<T>::iterator 
   insert_sorted( std::vector<T> & vec, T const& item )
{
    return vec.insert
        ( 
            std::upper_bound( vec.begin(), vec.end(), item ),
            item 
        );
}


int main() {
  int n;
  cin >> n;
  map<int, int> maxes;
  vector<int> roots;
//  vector< vector<int>> g;

  for(int i=0; i<n; i++) {
    int v;
    cin >> v;
    v = -1*v;
    if(roots.size() <= 0) {
      roots.push_back(v);
      // maxes[v] = v;
      continue;
    }

//    sort(roots.begin(), roots.end());
    auto index = upper_bound(roots.begin(), roots.end(), v);
    if(index != roots.end()) {
      roots.erase(index);
    }
    insert_sorted(roots,v);


    // for(auto r : roots) {
    //   cout << r << " ";
    // }
    // cout << endl;

    // bool f = true;
    // for(int r : roots) {
    //   if( maxes[r] < v ) {
    //     maxes[r] = v;
    //     f = false;
    //     break;
    //   }
    // }

    // if(f){
    //   roots.push_back(v);
    //   maxes[v] = v;
    // }
  }
  cout << roots.size() << endl;
}