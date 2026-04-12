#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const ll mx = 1000000000000;

int main(){
  int N;
  cin >> N;
  ll a[N];
  for(int i = 0; i < N; i++){
    cin >> a[i];
    a[i] = mx - a[i];
  }

  multiset<ll> st;
  st.insert(a[0]);
  for(int i = 1; i < N; i++){
    auto itr = st.upper_bound(a[i]);
    //cout << "hofe" << endl;
    if(itr == st.end()){
      st.insert(a[i]);
    } else {
      st.erase(itr);
      st.insert(a[i]);
    }
  }

  cout << st.size() << endl;
  return 0;
}