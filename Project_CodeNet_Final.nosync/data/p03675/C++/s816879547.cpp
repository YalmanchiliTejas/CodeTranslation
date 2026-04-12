#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <list>
#define all(x) x.begin(), x.end()
#define rep(n) for (int i=0; i<n; ++i)

using namespace std;

int main(void){
  int n;
  cin >> n;
  vector<int> front, back;
  rep(n){
    int cur;
    cin >> cur;
    if(i%2 == 0){
      front.push_back(cur);
    } else {
      back.push_back(cur);
    }
  }
  if (n%2 == 1) reverse(all(front));


  if(n%2 != 0){
    for(auto it = front.begin(); it != front.end(); ++it){
      cout << *it << " ";
    }
    for(auto it = back.begin(); it != back.end(); ++it){
      cout << *it;
      if (it != back.end()-1) cout << " ";
    }
  }else{
    for(auto it = back.end()-1; it >= back.begin(); --it){
      cout << *it << " ";
    }
    for(auto it = front.begin(); it != front.end(); ++it){
      cout << *it;
      if (it != front.end()-1) cout << " ";
    }
  }
  cout << endl;
  return 0;
}