#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intput(i) cout << i << endl
#define ll long long
#define stringput(s) cout << (string)(s) << endl

int main(){
  int N;
  cin >> N;
  vector<int> h(N);
  int j = 0;
    rep(i,N){
        cin >> h[i];
    }
  rep(i,N){
    int M = *max_element(h.begin(),h.begin()+i+1);
      if(M == h[i]) {
          j++;
      }
  }
  cout << j << endl;
}
