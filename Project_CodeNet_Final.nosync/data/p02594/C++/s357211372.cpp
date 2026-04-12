#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iterator>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <iomanip>
#include <climits>

using namespace std;
#define range(a) a.begin(), a.end()
#define rep(i, c) for(int i = 0; i < (int)c; i++)
typedef long long ll;

template <typename T> ostream& operator<<(ostream& out, vector<T> &v){
  for (int i = 0; i < (int)v.size(); i++) {
    out<<v[i]<<' ';
  }
  return out;
}

int main(){
  int n; cin >> n;
  if(n >= 30){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
