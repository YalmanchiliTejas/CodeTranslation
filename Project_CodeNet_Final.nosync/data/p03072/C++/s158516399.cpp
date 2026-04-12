#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);

  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  int max=0;
  int ans=0;
  for(int i=0;i<N;i++)
    if(max<=vec.at(i)){
      max=vec.at(i);
      ans++;
    }
  cout<<ans<<endl;

}
