#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int N;
  long long int sum = 0;

  cin >> N;

  vector< pair< long long int, int > > s(N);
  vector< long long int > t(N);
  long long int tmp;
  for(int i = 0; i < N; i++) {
    cin >> tmp;
    s[i].first = tmp; s[i].second = i;
    t[i] = tmp;
  }
  sort(s.begin(), s.end());

  vector< long long int > ans(N);
  for(int i = 0; i < N; i++) {
    if(i < N / 2) ans[s[i].second] = s[N/2].first;
    else ans[s[i].second] = s[N/2-1].first;
  }
  for(auto a : ans) cout << a << endl;

  return 0;
}
