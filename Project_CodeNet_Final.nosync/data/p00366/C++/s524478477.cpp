#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, T[100000];
  cin >> N;
  for(int i = 0; i < N; i++) cin >> T[i];
  int p = *max_element(T, T + N);
  vector< int > divisor;
  for(int i = 1; i * i <= p; i++) {
    if(p % i == 0) {
      divisor.push_back(i);
      if(i * i != p) divisor.push_back(p / i);
    }
  }
  sort(begin(divisor), end(divisor));
  int ret = 0;
  for(int i = 0; i < N; i++) {
    ret += *lower_bound(begin(divisor), end(divisor), T[i]) - T[i];
  }
  cout << ret << endl;
}