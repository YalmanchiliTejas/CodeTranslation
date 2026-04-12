#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i,n){
    cin >> h[i];
  }
  int highest=0;
  int sea=0;
  for(int i=0;i<n;i++){
    if(h[i]>=highest){
      highest = h[i];
      //cout << highest << endl;
      sea+=1;
    }
  }
    cout << sea << endl;
}