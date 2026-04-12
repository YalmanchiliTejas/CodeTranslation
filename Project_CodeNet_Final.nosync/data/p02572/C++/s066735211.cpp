#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  //cout << M << endl;*/

  vector<unsigned long long int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }

  unsigned long long int tmp_sum = 0;
  /*for(int i = 0; i < vec.size(); i++){
    tmp_sum = tmp_sum+vec.at(i);
  }*/

  unsigned long long int sum = 0;

  for(int i = 1; i < vec.size(); i++){
    tmp_sum = (tmp_sum + vec.at(i-1))% 1000000007;
    sum = (sum + vec.at(i) * tmp_sum) % 1000000007;
  }

  cout << sum % 1000000007 << endl;
  /*for (int i = 0; i < vec.size(); i ++){
    cout << vec.at(i) << endl;
  }

  for (int i = 0; i < vec.size()-1; i ++){
    cout << vec.at(i) << " ";
  }
  cout << vec.at(vec.size() - 1) << endl;*/
}
