#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin >> N;
  vector<int> v(N);
  for(int i=0;i<N;i++){
    cin >> v[i];
  }
  int ans = N;
  for(int i=0;i<N;i++){
    for(int j=0;j<i;j++){
      if(v[i]<v[j]) {
        ans--;
        break;
      }
    }
  }
  cout << ans << endl;
}
