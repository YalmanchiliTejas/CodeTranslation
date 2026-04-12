#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  multiset<int> st;
  for (int i = 0; i < N; i++){
    auto itr = st.lower_bound(A[i]);
    if (itr == st.begin()){
      st.insert(A[i]);
    } else {
      st.erase(prev(itr));
      st.insert(A[i]);
    }
  }
  cout << st.size() << endl;
}