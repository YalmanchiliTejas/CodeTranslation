#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
  int n;
  long long a[100005];
  multiset< long long > s;

  cin >> n;
  for(int i=0; i<n; i++) cin >> a[i];
  s.insert(a[0]);
  for(int i=1; i<n; i++){
    auto itr = s.lower_bound(a[i]);
    if(itr != s.begin()){
      itr--;
      s.erase(itr);
    }
    s.insert(a[i]);
    //cout << "size : " << s.size() << endl;
  }

  cout << s.size() << endl;

}