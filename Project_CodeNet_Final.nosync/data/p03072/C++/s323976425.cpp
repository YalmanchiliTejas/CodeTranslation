#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  int ans=1;
  bool flag=false;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if ((H.at(i)-H.at(j))>=0){
        flag=true;
      }else{
        flag=false;
        break;
      }
    }
    if (flag) ans++;
  }
  cout << ans << endl;
}
