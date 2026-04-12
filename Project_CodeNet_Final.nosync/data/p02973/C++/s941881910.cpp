#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

#define mmum 1e9
using vint = vector<int>;
using vvint = vector< vector<int> >;

int main(int argc, char* argv[]){
  int n; cin >> n;
  vint a;
  for(int i = 0; i < n ; i++){
    int t;
    cin >> t;
    t = mmum - t;
    auto it = upper_bound(a.begin(), a.end(), t);
    if(it != a.end()){
      *it = t;
    }
    else a.push_back(t);
  }
  cout << a.size() << endl;
}
