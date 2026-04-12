#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  while (cin >> n, n){
    int a;
    stack<pair<int, int> > st;
    
    cin >> a;
    st.emplace(a, 1);
    for (int i = 2; i <= n; i++){
      cin >> a;
      if (i % 2){
        auto &po = st.top();
        if (po.first == a){
          po.second++;
        } else {
          st.emplace(a, 1);
        }
      } else {
        auto po = st.top(); st.pop();
        if (po.first == a){
          po.second++;
          st.emplace(po);
        } else {
          if (st.empty()){
            st.emplace(a, po.second + 1);
          } else {
            st.top().second += 1 + po.second;
          }
        }
      }
    }

    int cnt = 0;
    while (!st.empty()){
      auto po = st.top(); st.pop();
      if (po.first) continue;
      cnt += po.second;
    }

    cout << cnt <<  endl;
  }
}